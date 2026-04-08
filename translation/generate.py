"""
Generation module for retrieval-augmented code translation.

This file:
- builds the translation prompt
- loads a Hugging Face causal language model
- generates translated target code

Example:
    python generate.py \
        --source-file ../examples/example.py \
        --retrieved-file ../examples/retrieved.json \
        --model bigcode/starcoder2-3b \
        --max-new-tokens 256
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any, Dict, List

import torch
from transformers import AutoModelForCausalLM, AutoTokenizer

from prompt_builder import TranslationConstraints, build_translation_prompt


class CodeTranslator:
    """
    Wrapper around a causal LM for code translation.

    Default usage:
    - provide source code
    - provide retrieved examples
    - generate target code
    """

    def __init__(
        self,
        model_name: str,
        device: str | None = None,
        torch_dtype: str = "auto",
    ) -> None:
        if device is None:
            device = "cuda" if torch.cuda.is_available() else "cpu"

        self.device = device
        self.tokenizer = AutoTokenizer.from_pretrained(model_name)

        dtype = None
        if torch_dtype == "float16":
            dtype = torch.float16
        elif torch_dtype == "bfloat16":
            dtype = torch.bfloat16
        elif torch_dtype == "float32":
            dtype = torch.float32

        model_kwargs = {}
        if dtype is not None:
            model_kwargs["torch_dtype"] = dtype

        self.model = AutoModelForCausalLM.from_pretrained(model_name, **model_kwargs)

        if self.tokenizer.pad_token is None:
            self.tokenizer.pad_token = self.tokenizer.eos_token

        if self.device == "cuda":
            self.model.to(self.device)

        self.model.eval()

    def generate(
        self,
        source_code: str,
        retrieved_examples: List[Dict[str, Any]],
        constraints: TranslationConstraints | None = None,
        max_new_tokens: int = 256,
        temperature: float = 0.2,
        top_p: float = 0.95,
        do_sample: bool = True,
    ) -> Dict[str, str]:
        prompt = build_translation_prompt(
            source_code=source_code,
            retrieved_examples=retrieved_examples,
            constraints=constraints,
        )

        inputs = self.tokenizer(
            prompt,
            return_tensors="pt",
            truncation=True,
            max_length=2048,
        )

        if self.device == "cuda":
            inputs = {k: v.to(self.device) for k, v in inputs.items()}

        with torch.no_grad():
            outputs = self.model.generate(
                **inputs,
                max_new_tokens=max_new_tokens,
                temperature=temperature,
                top_p=top_p,
                do_sample=do_sample,
                pad_token_id=self.tokenizer.pad_token_id,
                eos_token_id=self.tokenizer.eos_token_id,
            )

        full_text = self.tokenizer.decode(outputs[0], skip_special_tokens=True)
        generated_text = full_text[len(prompt):].strip() if full_text.startswith(prompt) else full_text.strip()

        return {
            "prompt": prompt,
            "generated_code": generated_text,
        }


def read_text_file(path: str | Path) -> str:
    file_path = Path(path)
    if not file_path.exists():
        raise FileNotFoundError(f"File not found: {file_path}")
    return file_path.read_text(encoding="utf-8")


def read_json_file(path: str | Path) -> Any:
    file_path = Path(path)
    if not file_path.exists():
        raise FileNotFoundError(f"File not found: {file_path}")
    with file_path.open("r", encoding="utf-8") as f:
        return json.load(f)


def maybe_save_output(output: Dict[str, str], output_path: str | Path | None) -> None:
    if output_path is None:
        return

    path = Path(output_path)
    path.parent.mkdir(parents=True, exist_ok=True)

    with path.open("w", encoding="utf-8") as f:
        json.dump(output, f, indent=2, ensure_ascii=False)


def main() -> None:
    parser = argparse.ArgumentParser(description="Generate translated code using retrieved examples.")
    parser.add_argument("--source-file", required=True, help="Path to input source code file.")
    parser.add_argument("--retrieved-file", required=True, help="Path to JSON file containing retrieved examples.")
    parser.add_argument("--model", default="bigcode/starcoder2-3b", help="Hugging Face causal LM name.")
    parser.add_argument("--max-new-tokens", type=int, default=256, help="Maximum generated tokens.")
    parser.add_argument("--temperature", type=float, default=0.2, help="Sampling temperature.")
    parser.add_argument("--top-p", type=float, default=0.95, help="Nucleus sampling parameter.")
    parser.add_argument("--output", default=None, help="Optional path to save JSON output.")
    args = parser.parse_args()

    source_code = read_text_file(args.source_file)
    retrieved_examples = read_json_file(args.retrieved_file)

    if not isinstance(retrieved_examples, list):
        raise ValueError("retrieved-file must contain a JSON list of retrieved examples.")

    constraints = TranslationConstraints(
        source_language="Python",
        target_language="C++",
        target_standard="C++17",
        preserve_function_name=True,
        use_stl=True,
        avoid_raw_pointers=True,
        prefer_const_references=True,
        output_code_only=True,
    )

    translator = CodeTranslator(model_name=args.model)
    output = translator.generate(
        source_code=source_code,
        retrieved_examples=retrieved_examples,
        constraints=constraints,
        max_new_tokens=args.max_new_tokens,
        temperature=args.temperature,
        top_p=args.top_p,
        do_sample=True,
    )

    maybe_save_output(output, args.output)

    print("=" * 80)
    print("PROMPT")
    print("=" * 80)
    print(output["prompt"])
    print()
    print("=" * 80)
    print("GENERATED CODE")
    print("=" * 80)
    print(output["generated_code"])


if __name__ == "__main__":
    main()
