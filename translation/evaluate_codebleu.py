from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any, Dict, List

import torch
from transformers import AutoModelForCausalLM, AutoTokenizer

from codebleu import calc_codebleu

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

    # If the model keeps generating explanation after code, this helps a little.
    stop_markers = [
        "\nExplanation:",
        "\nNotes:",
        "\nThe code",
        "\nThis code",
    ]

    for marker in stop_markers:
        if marker in text:
            text = text.split(marker, 1)[0]

    return text.strip()


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

    inputs = {k: v.to(model.device) for k, v in inputs.items()}

    with torch.no_grad():
        outputs = model.generate(
            **inputs,
            max_new_tokens=max_new_tokens,
            temperature=temperature,
            top_p=top_p,
            do_sample=do_sample,
            pad_token_id=tokenizer.pad_token_id,
            eos_token_id=tokenizer.eos_token_id,
        )

    decoded = tokenizer.decode(outputs[0], skip_special_tokens=True)

    if decoded.startswith(prompt):
        generated = decoded[len(prompt):]
    else:
        generated = decoded

    return clean_generated_code(generated)


def main() -> None:
    parser = argparse.ArgumentParser(description="Evaluate Python -> C++ model using CodeBLEU.")
    parser.add_argument("--test-data", required=True, help="Path to test JSON/JSONL.")
    parser.add_argument("--model", required=True, help="Trained model path or Hugging Face model name.")
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

    tokenizer = AutoTokenizer.from_pretrained(args.model)

    if tokenizer.pad_token is None:
        tokenizer.pad_token = tokenizer.eos_token

    model = AutoModelForCausalLM.from_pretrained(
        args.model,
        torch_dtype=torch.bfloat16 if args.bf16 else None,
        device_map="auto",
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

            print(f"[{idx + 1}/{len(records)}] generated id={example.get('id')}")

    codebleu_result = calc_codebleu(
        [[ref] for ref in references],
        predictions,
        lang="cpp",
        weights=(0.25, 0.25, 0.25, 0.25),
    )

    summary = {
        "total_examples": len(records),
        "codebleu": codebleu_result,
        "results_path": str(results_path),
    }

    with summary_path.open("w", encoding="utf-8") as f:
        json.dump(summary, f, indent=2, ensure_ascii=False)

    print(json.dumps(summary, indent=2, ensure_ascii=False))


if __name__ == "__main__":
    main()