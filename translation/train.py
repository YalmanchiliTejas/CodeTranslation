from __future__ import annotations

import argparse
import json
import os
from pathlib import Path
from typing import Any, Dict, List

import torch
from torch.utils.data import Dataset

from transformers import AutoModelForCausalLM, AutoTokenizer, Trainer, TrainingArguments
from transformers.trainer_utils import get_last_checkpoint
from peft import LoraConfig, TaskType, get_peft_model

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
        records: List[Dict[str, Any]] = []
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
        raise ValueError("Expected JSON list or JSONL.")

    if not data:
        raise ValueError(f"No records found in {path}")

    return data


def build_prompt(
    example: Dict[str, Any],
    *,
    max_problem_chars: int,
    max_sample_tests: int,
) -> str:
    problem_description = example.get("problem_description", "")
    if problem_description and len(problem_description) > max_problem_chars:
        problem_description = problem_description[:max_problem_chars].rstrip() + "\n...[truncated]"

    problem_context = ProblemContext(
        problem_id=example.get("problem_id", ""),
        problem_name=example.get("problem_name", ""),
        problem_description=problem_description,
        sample_tests=(example.get("sample_tests", []) or [])[:max_sample_tests],
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
        extra_rules=[
            "Generate only the final C++17 code.",
            "Do not include markdown fences.",
            "Do not explain the solution.",
        ],
    )

    retrieved_examples = example.get("retrieved_examples", [])

    return build_translation_prompt(
        source_code=example["source_code"].strip(),
        retrieved_examples=retrieved_examples,
        constraints=constraints,
        problem_context=problem_context,
        max_problem_chars=max_problem_chars,
        max_sample_tests=max_sample_tests,
    )


class CodeTranslationDataset(Dataset):
    def __init__(
        self,
        records: List[Dict[str, Any]],
        tokenizer,
        max_length: int = 4096,
        max_prompt_tokens: int = 2048,
        max_target_tokens: int = 1536,
        max_problem_chars: int = 1200,
        max_sample_tests: int = 2,
    ) -> None:
        self.records = records
        self.tokenizer = tokenizer
        self.max_length = max_length
        self.max_prompt_tokens = max_prompt_tokens
        self.max_target_tokens = max_target_tokens
        self.max_problem_chars = max_problem_chars
        self.max_sample_tests = max_sample_tests

        if max_prompt_tokens + max_target_tokens > max_length:
            raise ValueError("max_prompt_tokens + max_target_tokens must be <= max_length.")

    def __len__(self) -> int:
        return len(self.records)

    def __getitem__(self, idx: int) -> Dict[str, torch.Tensor]:
        example = self.records[idx]

        if "source_code" not in example:
            raise KeyError(f"Example {idx} is missing source_code.")
        if "target_code" not in example:
            raise KeyError(f"Example {idx} is missing target_code.")

        prompt = build_prompt(
            example,
            max_problem_chars=self.max_problem_chars,
            max_sample_tests=self.max_sample_tests,
        )

        target = "\n" + example["target_code"].strip()
        if self.tokenizer.eos_token:
            target += self.tokenizer.eos_token

        prompt_ids = self.tokenizer(prompt, add_special_tokens=False)["input_ids"]
        target_ids = self.tokenizer(target, add_special_tokens=False)["input_ids"]

        # Keep target tokens from being completely cut off.
        if len(target_ids) > self.max_target_tokens:
            target_ids = target_ids[: self.max_target_tokens]
            if self.tokenizer.eos_token_id is not None:
                target_ids[-1] = self.tokenizer.eos_token_id

        available_prompt_tokens = min(
            self.max_prompt_tokens,
            self.max_length - len(target_ids),
        )

        if available_prompt_tokens <= 0:
            target_ids = target_ids[: self.max_length // 2]
            available_prompt_tokens = self.max_length - len(target_ids)

        # Keep the END of the prompt because it contains the Python source and "C++17 Code:".
        if len(prompt_ids) > available_prompt_tokens:
            prompt_ids = prompt_ids[-available_prompt_tokens:]

        input_ids = prompt_ids + target_ids
        attention_mask = [1] * len(input_ids)
        labels = [-100] * len(prompt_ids) + target_ids.copy()

        pad_len = self.max_length - len(input_ids)
        if pad_len > 0:
            input_ids += [self.tokenizer.pad_token_id] * pad_len
            attention_mask += [0] * pad_len
            labels += [-100] * pad_len

        input_ids = input_ids[: self.max_length]
        attention_mask = attention_mask[: self.max_length]
        labels = labels[: self.max_length]

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

    model_kwargs = {
        "torch_dtype": dtype,
        "trust_remote_code": True,
        "low_cpu_mem_usage": False,
    }

    model = AutoModelForCausalLM.from_pretrained(
        args.model,
        **model_kwargs,
    )

    model.config.use_cache = False

    if args.gradient_checkpointing:
        model.gradient_checkpointing_enable()

    return model


def build_lora_model(model, args):
    target_modules = [
        item.strip()
        for item in args.lora_target_modules.split(",")
        if item.strip()
    ]

    lora_config = LoraConfig(
        task_type=TaskType.CAUSAL_LM,
        r=args.lora_r,
        lora_alpha=args.lora_alpha,
        lora_dropout=args.lora_dropout,
        bias="none",
        target_modules=target_modules,
    )

    model = get_peft_model(model, lora_config)
    model.print_trainable_parameters()
    return model


def print_token_debug(dataset: CodeTranslationDataset, n: int = 2) -> None:
    print("\nToken budget debug:")

    for i in range(min(n, len(dataset))):
        item = dataset[i]
        total = int(item["attention_mask"].sum().item())
        supervised = int((item["labels"] != -100).sum().item())
        print(f"Example {i}: total_nonpad={total}, supervised_target_tokens={supervised}")
        if supervised == 0:
            print("WARNING: zero supervised target tokens.")


def build_training_args(args, world_size: int):
    kwargs = dict(
        output_dir=args.output_dir,
        num_train_epochs=args.epochs,
        per_device_train_batch_size=args.batch_size,
        per_device_eval_batch_size=args.batch_size,
        gradient_accumulation_steps=args.grad_accum,
        learning_rate=args.lr,
        logging_steps=args.logging_steps,
        eval_steps=args.eval_steps,
        save_steps=args.save_steps,
        save_total_limit=args.save_total_limit,
        warmup_ratio=args.warmup_ratio,
        weight_decay=args.weight_decay,
        max_grad_norm=args.max_grad_norm,
        fp16=args.fp16,
        bf16=args.bf16,
        report_to="none",
        remove_unused_columns=False,
        optim="adamw_torch",
        ddp_find_unused_parameters=False if world_size > 1 else None,
        load_best_model_at_end=False,
    )

    try:
        return TrainingArguments(
            eval_strategy="steps",
            save_strategy="steps",
            **kwargs,
        )
    except TypeError:
        return TrainingArguments(
            evaluation_strategy="steps",
            save_strategy="steps",
            **kwargs,
        )


def build_trainer(model, training_args, train_dataset, valid_dataset, tokenizer):
    try:
        return Trainer(
            model=model,
            args=training_args,
            train_dataset=train_dataset,
            eval_dataset=valid_dataset,
            processing_class=tokenizer,
        )
    except TypeError:
        return Trainer(
            model=model,
            args=training_args,
            train_dataset=train_dataset,
            eval_dataset=valid_dataset,
        )


def get_resume_checkpoint(args) -> str | None:
    if args.resume_from_checkpoint:
        checkpoint_path = Path(args.resume_from_checkpoint)
        if not checkpoint_path.exists():
            raise FileNotFoundError(f"--resume-from-checkpoint does not exist: {checkpoint_path}")
        return str(checkpoint_path)

    if args.auto_resume:
        output_dir = Path(args.output_dir)
        if output_dir.exists():
            last_checkpoint = get_last_checkpoint(str(output_dir))
            if last_checkpoint is not None:
                return last_checkpoint

    return None


def save_model_and_tokenizer(args, model, tokenizer) -> None:
    output_dir = Path(args.output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)

    model.save_pretrained(args.output_dir)
    tokenizer.save_pretrained(args.output_dir)

    print(f"Saved final model to {args.output_dir}")
    print("Saved files:")
    for path in sorted(output_dir.glob("*")):
        print(f"  {path}")


def main() -> None:
    parser = argparse.ArgumentParser(description="Train Python -> C++ LoRA model with resume support.")

    parser.add_argument("--train-data", required=True)
    parser.add_argument("--valid-data", required=True)
    parser.add_argument("--model", default="bigcode/starcoder2-3b")
    parser.add_argument("--output-dir", default="checkpoints/python_to_cpp_lora")

    parser.add_argument("--max-length", type=int, default=4096)
    parser.add_argument("--max-prompt-tokens", type=int, default=2048)
    parser.add_argument("--max-target-tokens", type=int, default=1536)
    parser.add_argument("--max-problem-chars", type=int, default=1200)
    parser.add_argument("--max-sample-tests", type=int, default=2)

    parser.add_argument("--epochs", type=float, default=5.0)
    parser.add_argument("--batch-size", type=int, default=1)
    parser.add_argument("--grad-accum", type=int, default=16)
    parser.add_argument("--lr", type=float, default=5e-5)
    parser.add_argument("--warmup-ratio", type=float, default=0.05)
    parser.add_argument("--weight-decay", type=float, default=0.01)
    parser.add_argument("--max-grad-norm", type=float, default=1.0)

    parser.add_argument("--use-lora", action="store_true")
    parser.add_argument("--lora-r", type=int, default=16)
    parser.add_argument("--lora-alpha", type=int, default=32)
    parser.add_argument("--lora-dropout", type=float, default=0.05)
    parser.add_argument(
        "--lora-target-modules",
        default="q_proj,k_proj,v_proj,o_proj,gate_proj,up_proj,down_proj",
    )

    parser.add_argument("--fp16", action="store_true")
    parser.add_argument("--bf16", action="store_true")
    parser.add_argument("--gradient-checkpointing", action="store_true")

    parser.add_argument("--logging-steps", type=int, default=25)
    parser.add_argument("--eval-steps", type=int, default=100)
    parser.add_argument("--save-steps", type=int, default=100)
    parser.add_argument("--save-total-limit", type=int, default=3)

    parser.add_argument("--auto-resume", action="store_true")
    parser.add_argument("--resume-from-checkpoint", default=None)

    args = parser.parse_args()

    local_rank = int(os.environ.get("LOCAL_RANK", "-1"))
    world_size = int(os.environ.get("WORLD_SIZE", "1"))
    is_main = local_rank in [-1, 0]

    if is_main:
        print("Training configuration:")
        print(json.dumps(vars(args), indent=2))
        print(f"LOCAL_RANK={local_rank}")
        print(f"WORLD_SIZE={world_size}")

    train_records = load_json_or_jsonl(args.train_data)
    valid_records = load_json_or_jsonl(args.valid_data)

    if is_main:
        print(f"Loaded {len(train_records)} training records.")
        print(f"Loaded {len(valid_records)} validation records.")

    tokenizer = AutoTokenizer.from_pretrained(
        args.model,
        use_fast=False,
        trust_remote_code=True,
    )

    if tokenizer.pad_token is None:
        tokenizer.pad_token = tokenizer.eos_token

    if tokenizer.pad_token_id is None:
        raise ValueError("Tokenizer has no pad_token_id.")

    model = load_base_model(args)

    if args.use_lora:
        model = build_lora_model(model, args)

    train_dataset = CodeTranslationDataset(
        train_records,
        tokenizer=tokenizer,
        max_length=args.max_length,
        max_prompt_tokens=args.max_prompt_tokens,
        max_target_tokens=args.max_target_tokens,
        max_problem_chars=args.max_problem_chars,
        max_sample_tests=args.max_sample_tests,
    )

    valid_dataset = CodeTranslationDataset(
        valid_records,
        tokenizer=tokenizer,
        max_length=args.max_length,
        max_prompt_tokens=args.max_prompt_tokens,
        max_target_tokens=args.max_target_tokens,
        max_problem_chars=args.max_problem_chars,
        max_sample_tests=args.max_sample_tests,
    )

    if is_main:
        print_token_debug(train_dataset)

    training_args = build_training_args(args, world_size)

    trainer = build_trainer(
        model=model,
        training_args=training_args,
        train_dataset=train_dataset,
        valid_dataset=valid_dataset,
        tokenizer=tokenizer,
    )

    resume_checkpoint = get_resume_checkpoint(args)

    if is_main:
        if resume_checkpoint:
            print(f"Resuming training from checkpoint: {resume_checkpoint}")
        else:
            print("Starting training from scratch.")

    trainer.train(resume_from_checkpoint=resume_checkpoint)

    if is_main:
        save_model_and_tokenizer(args, model, tokenizer)

    if world_size > 1:
        torch.distributed.barrier()


if __name__ == "__main__":
    main()