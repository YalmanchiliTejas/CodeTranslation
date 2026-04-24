from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any, Dict, List

import torch
from torch.utils.data import Dataset

from transformers import (
    AutoModelForCausalLM,
    AutoTokenizer,
    Trainer,
    TrainingArguments,
)

from peft import LoraConfig, get_peft_model, TaskType

from translation.prompt_builder import (
    ProblemContext,
    TranslationConstraints,
    build_translation_prompt,
)


def load_json_or_jsonl(path: str | Path) -> List[Dict[str, Any]]:
    path = Path(path)

    if not path.exists():
        raise FileNotFoundError(f"Dataset file not found: {path}")

    if path.suffix.lower() == ".jsonl":
        records = []
        with path.open("r", encoding="utf-8") as f:
            for line in f:
                if line.strip():
                    records.append(json.loads(line))
        return records

    with path.open("r", encoding="utf-8") as f:
        data = json.load(f)

    if not isinstance(data, list):
        raise ValueError("Expected a JSON list or JSONL file.")

    return data


def build_prompt(example: Dict[str, Any]) -> str:
    problem_context = ProblemContext(
        problem_id=example.get("problem_id", ""),
        problem_name=example.get("problem_name", ""),
        problem_description=example.get("problem_description", ""),
        sample_tests=example.get("sample_tests", []),
    )

    constraints = TranslationConstraints(
        source_language="Python",
        target_language="C++",
        target_standard="C++17",
        preserve_function_name=False,
        use_stl=True,
        avoid_raw_pointers=True,
        prefer_const_references=True,
        output_code_only=True,
    )

    return build_translation_prompt(
        source_code=example["source_code"],
        retrieved_examples=[],
        constraints=constraints,
        problem_context=problem_context,
    )


class CodeTranslationDataset(Dataset):
    def __init__(
        self,
        records: List[Dict[str, Any]],
        tokenizer,
        max_length: int = 4096,
    ) -> None:
        self.records = records
        self.tokenizer = tokenizer
        self.max_length = max_length

    def __len__(self) -> int:
        return len(self.records)

    def __getitem__(self, idx: int) -> Dict[str, torch.Tensor]:
        example = self.records[idx]

        if "source_code" not in example:
            raise KeyError(f"Example {idx} is missing source_code.")
        if "target_code" not in example:
            raise KeyError(f"Example {idx} is missing target_code.")

        prompt = build_prompt(example)
        target = example["target_code"].strip() + self.tokenizer.eos_token

        prompt_tokens = self.tokenizer(
            prompt,
            add_special_tokens=False,
        )

        full_tokens = self.tokenizer(
            prompt + target,
            truncation=True,
            max_length=self.max_length,
            padding="max_length",
            add_special_tokens=False,
        )

        input_ids = full_tokens["input_ids"]
        attention_mask = full_tokens["attention_mask"]

        labels = input_ids.copy()

        prompt_len = len(prompt_tokens["input_ids"])
        prompt_len = min(prompt_len, self.max_length)

        # Ignore loss on prompt tokens.
        labels[:prompt_len] = [-100] * prompt_len

        # Ignore padding tokens.
        labels = [
            label if mask == 1 else -100
            for label, mask in zip(labels, attention_mask)
        ]

        return {
            "input_ids": torch.tensor(input_ids, dtype=torch.long),
            "attention_mask": torch.tensor(attention_mask, dtype=torch.long),
            "labels": torch.tensor(labels, dtype=torch.long),
        }


def main() -> None:
    parser = argparse.ArgumentParser(description="Train Python -> C++ code translation model.")
    parser.add_argument("--train-data", required=True, help="Path to train JSON/JSONL.")
    parser.add_argument("--valid-data", required=True, help="Path to validation JSON/JSONL.")
    parser.add_argument("--model", default="bigcode/starcoder2-3b", help="Base model name.")
    parser.add_argument("--output-dir", default="checkpoints/python_to_cpp_lora", help="Output directory.")
    parser.add_argument("--max-length", type=int, default=4096)
    parser.add_argument("--epochs", type=float, default=1.0)
    parser.add_argument("--batch-size", type=int, default=1)
    parser.add_argument("--grad-accum", type=int, default=8)
    parser.add_argument("--lr", type=float, default=2e-4)
    parser.add_argument("--use-lora", action="store_true", help="Use LoRA fine-tuning.")
    parser.add_argument("--fp16", action="store_true")
    parser.add_argument("--bf16", action="store_true")
    args = parser.parse_args()

    train_records = load_json_or_jsonl(args.train_data)
    valid_records = load_json_or_jsonl(args.valid_data)

    tokenizer = AutoTokenizer.from_pretrained(args.model)

    if tokenizer.pad_token is None:
        tokenizer.pad_token = tokenizer.eos_token

    model = AutoModelForCausalLM.from_pretrained(
        args.model,
        torch_dtype=torch.bfloat16 if args.bf16 else None,
        device_map="auto",
    )

    if args.use_lora:
        lora_config = LoraConfig(
            task_type=TaskType.CAUSAL_LM,
            r=16,
            lora_alpha=32,
            lora_dropout=0.05,
            bias="none",
            target_modules=[
                "q_proj",
                "k_proj",
                "v_proj",
                "o_proj",
                "gate_proj",
                "up_proj",
                "down_proj",
            ],
        )

        model = get_peft_model(model, lora_config)
        model.print_trainable_parameters()

    train_dataset = CodeTranslationDataset(
        train_records,
        tokenizer=tokenizer,
        max_length=args.max_length,
    )

    valid_dataset = CodeTranslationDataset(
        valid_records,
        tokenizer=tokenizer,
        max_length=args.max_length,
    )

    training_args = TrainingArguments(
        output_dir=args.output_dir,
        num_train_epochs=args.epochs,
        per_device_train_batch_size=args.batch_size,
        per_device_eval_batch_size=args.batch_size,
        gradient_accumulation_steps=args.grad_accum,
        learning_rate=args.lr,
        logging_steps=25,
        eval_strategy="steps",
        eval_steps=250,
        save_steps=250,
        save_total_limit=2,
        warmup_ratio=0.03,
        weight_decay=0.01,
        fp16=args.fp16,
        bf16=args.bf16,
        report_to="none",
        remove_unused_columns=False,
    )

    trainer = Trainer(
        model=model,
        args=training_args,
        train_dataset=train_dataset,
        eval_dataset=valid_dataset,
        tokenizer=tokenizer,
    )

    trainer.train()

    trainer.save_model(args.output_dir)
    tokenizer.save_pretrained(args.output_dir)

    print(f"Saved trained model to {args.output_dir}")


if __name__ == "__main__":
    main()