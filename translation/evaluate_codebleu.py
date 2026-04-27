from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any, Dict, List

import torch
from transformers import AutoModelForCausalLM, AutoTokenizer
from peft import PeftModel

from codebleu import calc_codebleu

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

        return records

    with path.open("r", encoding="utf-8") as f:
        data = json.load(f)

    if not isinstance(data, list):
        raise ValueError("Expected a JSON list or JSONL file.")

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


def clean_generated_code(text: str) -> str:
    text = text.strip()

    if "```cpp" in text:
        text = text.split("```cpp", 1)[1]
        text = text.split("```", 1)[0]
    elif "```c++" in text:
        text = text.split("```c++", 1)[1]
        text = text.split("```", 1)[0]
    elif "```" in text:
        text = text.split("```", 1)[1]
        text = text.split("```", 1)[0]

    stop_markers = [
        "\nExplanation:",
        "\nNotes:",
        "\nThe code",
        "\nThis code",
        "\nSource Code:",
        "\nTarget Code:",
    ]

    for marker in stop_markers:
        if marker in text:
            text = text.split(marker, 1)[0]

    return text.strip()


def get_model_device(model) -> torch.device:
    try:
        return next(model.parameters()).device
    except StopIteration:
        return torch.device("cuda" if torch.cuda.is_available() else "cpu")


def load_tokenizer(base_model: str):
    """
    Always load tokenizer from the base model, not the LoRA adapter checkpoint.
    The LoRA checkpoint often does not contain a full tokenizer.
    """
    tokenizer = AutoTokenizer.from_pretrained(
        base_model,
        use_fast=False,
        trust_remote_code=True,
    )

    if tokenizer.pad_token is None:
        tokenizer.pad_token = tokenizer.eos_token

    return tokenizer


def load_model(model_path: str, base_model: str, bf16: bool):
    """
    Loads either:
    1. LoRA adapter checkpoint from model_path + base model from base_model, or
    2. full model from model_path if no adapter_config.json exists.
    """
    dtype = torch.bfloat16 if bf16 else None

    model_path_obj = Path(model_path)
    adapter_config = model_path_obj / "adapter_config.json"

    if adapter_config.exists():
        print(f"Detected LoRA adapter checkpoint: {model_path}")
        print(f"Loading base model: {base_model}")

        base = AutoModelForCausalLM.from_pretrained(
            base_model,
            torch_dtype=dtype,
            device_map="auto",
            trust_remote_code=True,
        )

        model = PeftModel.from_pretrained(
            base,
            model_path,
            torch_dtype=dtype,
            device_map="auto",
        )

        return model

    print(f"No adapter_config.json found. Loading full model from: {model_path}")

    model = AutoModelForCausalLM.from_pretrained(
        model_path,
        torch_dtype=dtype,
        device_map="auto",
        trust_remote_code=True,
    )

    return model


def generate_one(
    model,
    tokenizer,
    prompt: str,
    max_new_tokens: int,
    temperature: float,
    top_p: float,
    do_sample: bool,
) -> str:
    inputs = tokenizer(
        prompt,
        return_tensors="pt",
        truncation=True,
        max_length=4096,
    )

    device = get_model_device(model)
    inputs = {k: v.to(device) for k, v in inputs.items()}

    generation_kwargs = {
        "max_new_tokens": max_new_tokens,
        "do_sample": do_sample,
        "pad_token_id": tokenizer.pad_token_id,
        "eos_token_id": tokenizer.eos_token_id,
    }

    if do_sample:
        generation_kwargs["temperature"] = temperature
        generation_kwargs["top_p"] = top_p

    with torch.no_grad():
        outputs = model.generate(
            **inputs,
            **generation_kwargs,
        )

    decoded = tokenizer.decode(outputs[0], skip_special_tokens=True)

    if decoded.startswith(prompt):
        generated = decoded[len(prompt):]
    else:
        generated = decoded

    return clean_generated_code(generated)


def compute_codebleu_strict(
    references: List[str],
    predictions: List[str],
) -> tuple[str, Dict[str, float]]:
    """
    Computes original/full CodeBLEU only.

    This intentionally does not fall back to BLEU/ngram scoring.
    If CodeBLEU or tree-sitter is broken, this function should fail loudly.
    """
    codebleu_result = calc_codebleu(
        [[ref] for ref in references],
        predictions,
        lang="cpp",
        weights=(0.25, 0.25, 0.25, 0.25),
    )

    return "full_codebleu", codebleu_result


def main() -> None:
    parser = argparse.ArgumentParser(description="Evaluate Python -> C++ model using full CodeBLEU.")
    parser.add_argument("--test-data", required=True, help="Path to test JSON/JSONL.")
    parser.add_argument("--model", required=True, help="Trained model path or Hugging Face model name.")
    parser.add_argument(
        "--base-model",
        default="bigcode/starcoder2-3b",
        help="Base model used for tokenizer and LoRA adapter loading.",
    )
    parser.add_argument("--results-out", required=True, help="Path to write per-example JSONL results.")
    parser.add_argument("--summary-out", required=True, help="Path to write summary JSON.")
    parser.add_argument("--max-examples", type=int, default=None)
    parser.add_argument("--max-new-tokens", type=int, default=512)
    parser.add_argument("--temperature", type=float, default=0.0)
    parser.add_argument("--top-p", type=float, default=1.0)
    parser.add_argument("--do-sample", action="store_true")
    parser.add_argument("--bf16", action="store_true")
    args = parser.parse_args()

    records = load_json_or_jsonl(args.test_data)

    if args.max_examples is not None:
        records = records[: args.max_examples]

    if not records:
        raise ValueError("No test records found.")

    tokenizer = load_tokenizer(args.base_model)

    model = load_model(
        model_path=args.model,
        base_model=args.base_model,
        bf16=args.bf16,
    )

    model.eval()

    results_path = Path(args.results_out)
    summary_path = Path(args.summary_out)

    results_path.parent.mkdir(parents=True, exist_ok=True)
    summary_path.parent.mkdir(parents=True, exist_ok=True)

    predictions: List[str] = []
    references: List[str] = []

    with results_path.open("w", encoding="utf-8") as out:
        for idx, example in enumerate(records):
            if "source_code" not in example:
                raise KeyError(f"Example {idx} is missing source_code.")
            if "target_code" not in example:
                raise KeyError(f"Example {idx} is missing target_code.")

            prompt = build_prompt(example)

            generated_code = generate_one(
                model=model,
                tokenizer=tokenizer,
                prompt=prompt,
                max_new_tokens=args.max_new_tokens,
                temperature=args.temperature,
                top_p=args.top_p,
                do_sample=args.do_sample,
            )

            reference_code = example["target_code"].strip()

            predictions.append(generated_code)
            references.append(reference_code)

            record = {
                "id": example.get("id"),
                "problem_id": example.get("problem_id"),
                "source_code": example["source_code"],
                "reference_code": reference_code,
                "generated_code": generated_code,
            }

            out.write(json.dumps(record, ensure_ascii=False) + "\n")
            out.flush()

            print(f"[{idx + 1}/{len(records)}] generated id={example.get('id')}")

    codebleu_mode, codebleu_result = compute_codebleu_strict(
        references=references,
        predictions=predictions,
    )

    summary = {
        "total_examples": len(records),
        "base_model": args.base_model,
        "model": args.model,
        "codebleu_mode": codebleu_mode,
        "codebleu": codebleu_result,
        "results_path": str(results_path),
    }

    with summary_path.open("w", encoding="utf-8") as f:
        json.dump(summary, f, indent=2, ensure_ascii=False)

    print(json.dumps(summary, indent=2, ensure_ascii=False))


if __name__ == "__main__":
    main()