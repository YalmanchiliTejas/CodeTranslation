from __future__ import annotations

import argparse
import json
import os
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
            for line_num, line in enumerate(f, start=1):
                line = line.strip()

                if not line:
                    continue

                try:
                    records.append(json.loads(line))
                except json.JSONDecodeError as e:
                    raise ValueError(f"Invalid JSON on line {line_num}: {e}") from e

        if not records:
            raise ValueError(f"No records found in {path}")

        return records

    with path.open("r", encoding="utf-8") as f:
        data = json.load(f)

    if not isinstance(data, list):
        raise ValueError("Expected a JSON list or JSONL file.")

    if not data:
        raise ValueError(f"No records found in {path}")

    return data


def build_prompt(example: Dict[str, Any]) -> str:
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

    problem_context_parts = []

    if example.get("problem_id"):
        problem_context_parts.append(f"Problem ID: {example['problem_id']}")

    if example.get("problem_name"):
        problem_context_parts.append(f"Problem Name: {example['problem_name']}")

    if example.get("problem_description"):
        problem_context_parts.append(
            "Problem Description:\n" + example["problem_description"].strip()
        )

    if example.get("sample_tests"):
        sample_text = ["Sample Tests:"]

        for i, test in enumerate(example["sample_tests"], start=1):
            sample_text.append(f"Sample Input {i}:\n{test.get('input', '').strip()}")
            sample_text.append(f"Sample Output {i}:\n{test.get('output', '').strip()}")

        problem_context_parts.append("\n".join(sample_text))

    problem_context = "\n\n".join(problem_context_parts).strip()

    if problem_context:
        source_code = f"""{problem_context}

Python Source Code:
{example["source_code"].strip()}
"""
    else:
        source_code = example["source_code"].strip()

    return build_translation_prompt(
        source_code=source_code,
        retrieved_examples=[],
        constraints=constraints,
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

        # Ignore prompt tokens in the loss.
        labels[:prompt_len] = [-100] * prompt_len

        # Ignore padding tokens in the loss.
        labels = [
            label if mask == 1 else -100
            for label, mask in zip(labels, attention_mask)
        ]

        return {
            "input_ids": torch.tensor(input_ids, dtype=torch.long),
            "attention_mask": torch.tensor(attention_mask, dtype=torch.long),
            "labels": torch.tensor(labels, dtype=torch.long),
        }


def get_dtype(args) -> torch.dtype | None:
    if args.bf16:
        return torch.bfloat16

    if args.fp16:
        return torch.float16

    return None


def load_base_model(args):
    dtype = get_dtype(args)

    local_rank = int(os.environ.get("LOCAL_RANK", "-1"))
    world_size = int(os.environ.get("WORLD_SIZE", "1"))

    model_kwargs = {
        "torch_dtype": dtype,
        "trust_remote_code": True,
    }

    # Important:
    # - For normal single-process training, device_map="auto" is fine.
    # - For torchrun/DDP, do NOT use device_map="auto". Each process owns one GPU.
    if world_size <= 1:
        model_kwargs["device_map"] = "auto"

    model = AutoModelForCausalLM.from_pretrained(
        args.model,
        **model_kwargs,
    )

    model.config.use_cache = False

    if world_size > 1:
        if not torch.cuda.is_available():
            raise RuntimeError("Distributed training was requested, but CUDA is not available.")

        if local_rank < 0:
            raise RuntimeError("WORLD_SIZE > 1 but LOCAL_RANK is not set.")

        torch.cuda.set_device(local_rank)
        model.to(torch.device("cuda", local_rank))

    return model


def build_lora_model(model):
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

    return model


def save_model_and_tokenizer(args, model, tokenizer) -> None:
    output_dir = Path(args.output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)

    if args.use_lora:
        model.save_pretrained(args.output_dir)
    else:
        model.save_pretrained(args.output_dir)

    tokenizer.save_pretrained(args.output_dir)

    print(f"Saved trained model to {args.output_dir}")
    print("Saved files:")

    for path in sorted(output_dir.glob("*")):
        print(f"  {path}")


def main() -> None:
    parser = argparse.ArgumentParser(description="Train Python -> C++ code translation model.")

    parser.add_argument("--train-data", required=True)
    parser.add_argument("--valid-data", required=True)
    parser.add_argument("--model", default="bigcode/starcoder2-3b")
    parser.add_argument("--output-dir", default="checkpoints/python_to_cpp_lora")

    parser.add_argument("--max-length", type=int, default=4096)
    parser.add_argument("--epochs", type=float, default=3.0)
    parser.add_argument("--batch-size", type=int, default=1)
    parser.add_argument("--grad-accum", type=int, default=16)
    parser.add_argument("--lr", type=float, default=1e-4)

    parser.add_argument("--use-lora", action="store_true")
    parser.add_argument("--fp16", action="store_true")
    parser.add_argument("--bf16", action="store_true")

    parser.add_argument("--logging-steps", type=int, default=25)
    parser.add_argument("--eval-steps", type=int, default=250)
    parser.add_argument("--save-steps", type=int, default=250)
    parser.add_argument("--save-total-limit", type=int, default=2)

    args = parser.parse_args()

    local_rank = int(os.environ.get("LOCAL_RANK", "-1"))
    world_size = int(os.environ.get("WORLD_SIZE", "1"))
    is_main_process = local_rank in [-1, 0]

    if is_main_process:
        print("Training configuration:")
        print(json.dumps(vars(args), indent=2))
        print(f"LOCAL_RANK={local_rank}")
        print(f"WORLD_SIZE={world_size}")

    train_records = load_json_or_jsonl(args.train_data)
    valid_records = load_json_or_jsonl(args.valid_data)

    if is_main_process:
        print(f"Loaded {len(train_records)} training records.")
        print(f"Loaded {len(valid_records)} validation records.")

    tokenizer = AutoTokenizer.from_pretrained(
        args.model,
        use_fast=False,
        trust_remote_code=True,
    )

    if tokenizer.pad_token is None:
        tokenizer.pad_token = tokenizer.eos_token

    model = load_base_model(args)

    if args.use_lora:
        model = build_lora_model(model)

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
        logging_steps=args.logging_steps,
        eval_strategy="steps",
        eval_steps=args.eval_steps,
        save_steps=args.save_steps,
        save_total_limit=args.save_total_limit,
        warmup_ratio=0.03,
        weight_decay=0.01,
        fp16=args.fp16,
        bf16=args.bf16,
        report_to="none",
        remove_unused_columns=False,
        ddp_find_unused_parameters=False if world_size > 1 else None,
    )

    # Newer transformers versions use processing_class instead of tokenizer.
    try:
        trainer = Trainer(
            model=model,
            args=training_args,
            train_dataset=train_dataset,
            eval_dataset=valid_dataset,
            processing_class=tokenizer,
        )
    except TypeError:
        # Older/newer compatibility fallback.
        trainer = Trainer(
            model=model,
            args=training_args,
            train_dataset=train_dataset,
            eval_dataset=valid_dataset,
        )

    trainer.train()

    # In distributed training, only the main process should write final files.
    if is_main_process:
        save_model_and_tokenizer(args, model, tokenizer)

    if world_size > 1:
        torch.distributed.barrier()


if __name__ == "__main__":
    main()