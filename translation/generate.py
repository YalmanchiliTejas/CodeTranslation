"""
Generation module for retrieval-augmented Python -> C++ translation with optional LoRA loading.

Supports:
- base model only
- base model + PEFT/LoRA adapter
- retrieved examples
- verification feedback repair prompts
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any, Dict, List

import torch
from peft import PeftModel
from transformers import AutoModelForCausalLM, AutoTokenizer

from translation.prompt_builder import (
    ProblemContext,
    TranslationConstraints,
    VerificationFeedback,
    build_translation_prompt,
)
from retrieval.search import CodeSearcher
from translation.verifier import CppVerifier


def clean_generated_code(text: str) -> str:
    text = text.strip()

    if "```cpp" in text:
        text = text.split("```cpp", 1)[1].split("```", 1)[0]
    elif "```c++" in text:
        text = text.split("```c++", 1)[1].split("```", 1)[0]
    elif "```" in text:
        text = text.split("```", 1)[1].split("```", 1)[0]

    stop_markers = [
        "\nExplanation:",
        "\nNotes:",
        "\nThe code",
        "\nThis code",
        "\nPython Source Code:",
        "\nC++17 Code:",
    ]

    for marker in stop_markers:
        if marker in text:
            text = text.split(marker, 1)[0]

    return text.strip()


class CodeTranslator:
    """
    Wrapper around a causal LM for retrieval-augmented Python -> C++ translation.

    Supports either:
    1. full/base model path or Hugging Face model name
    2. LoRA adapter path + base model name
    """

    def __init__(
        self,
        model_name: str,
        base_model: str | None = None,
        device: str | None = None,
        torch_dtype: str = "auto",
    ) -> None:
        if device is None:
            device = "cuda" if torch.cuda.is_available() else "cpu"

        self.device = device

        dtype = None
        if torch_dtype == "float16":
            dtype = torch.float16
        elif torch_dtype == "bfloat16":
            dtype = torch.bfloat16
        elif torch_dtype == "float32":
            dtype = torch.float32

        model_path = Path(model_name)
        adapter_config = model_path / "adapter_config.json"

        if adapter_config.exists():
            if base_model is None:
                raise ValueError(
                    "LoRA adapter detected, but base_model was not provided. "
                    "Pass --base-model bigcode/starcoder2-3b."
                )

            print(f"Detected LoRA adapter: {model_name}")
            print(f"Loading tokenizer/base model from: {base_model}")

            self.tokenizer = AutoTokenizer.from_pretrained(
                base_model,
                use_fast=False,
                trust_remote_code=True,
            )

            base = AutoModelForCausalLM.from_pretrained(
                base_model,
                torch_dtype=dtype,
                device_map="auto" if device == "cuda" else None,
                trust_remote_code=True,
            )

            self.model = PeftModel.from_pretrained(
                base,
                model_name,
                torch_dtype=dtype,
                device_map="auto" if device == "cuda" else None,
            )

        else:
            print(f"Loading full/base model from: {model_name}")

            self.tokenizer = AutoTokenizer.from_pretrained(
                model_name,
                use_fast=False,
                trust_remote_code=True,
            )

            self.model = AutoModelForCausalLM.from_pretrained(
                model_name,
                torch_dtype=dtype,
                device_map="auto" if device == "cuda" else None,
                trust_remote_code=True,
            )

        if self.tokenizer.pad_token is None:
            self.tokenizer.pad_token = self.tokenizer.eos_token

        if self.device == "cuda" and not hasattr(self.model, "hf_device_map"):
            self.model.to(self.device)

        self.model.eval()

    def _model_device(self) -> torch.device:
        try:
            return next(self.model.parameters()).device
        except StopIteration:
            return torch.device("cuda" if torch.cuda.is_available() else "cpu")

    def generate_from_prompt(
    self,
    prompt: str,
    *,
    max_new_tokens: int = 1024,
    temperature: float = 0.0,
    top_p: float = 1.0,
    do_sample: bool = False,
) -> str:
        inputs = self.tokenizer(
            prompt,
            return_tensors="pt",
            truncation=True,
            max_length=4096,
        )

        device = self._model_device()
        inputs = {k: v.to(device) for k, v in inputs.items()}

        generation_kwargs = {
            "max_new_tokens": max_new_tokens,
            "do_sample": do_sample,
            "pad_token_id": self.tokenizer.pad_token_id,
            "eos_token_id": self.tokenizer.eos_token_id,
        }

        if do_sample:
            generation_kwargs["temperature"] = temperature
            generation_kwargs["top_p"] = top_p

        with torch.no_grad():
            outputs = self.model.generate(
                **inputs,
                **generation_kwargs,
            )

        # IMPORTANT:
        # outputs[0] contains prompt tokens + newly generated tokens.
        # Slice by token length, not string matching.
        input_len = inputs["input_ids"].shape[-1]
        generated_ids = outputs[0][input_len:]

        generated_text = self.tokenizer.decode(
            generated_ids,
            skip_special_tokens=True,
        )

        return clean_generated_code(generated_text)

    def generate(
        self,
        *,
        source_code: str,
        retrieved_examples: List[Dict[str, Any]],
        problem_context: ProblemContext | None = None,
        constraints: TranslationConstraints | None = None,
        previous_attempt: str | None = None,
        verification_feedback: VerificationFeedback | None = None,
        max_new_tokens: int = 1024,
        temperature: float = 0.0,
        top_p: float = 1.0,
        do_sample: bool = False,
    ) -> Dict[str, str]:
        prompt = build_translation_prompt(
            source_code=source_code,
            retrieved_examples=retrieved_examples,
            constraints=constraints,
            problem_context=problem_context,
            previous_attempt=previous_attempt,
            verification_feedback=verification_feedback,
        )

        generated_code = self.generate_from_prompt(
            prompt,
            max_new_tokens=max_new_tokens,
            temperature=temperature,
            top_p=top_p,
            do_sample=do_sample,
        )

        return {
            "prompt": prompt,
            "generated_code": generated_code,
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


def maybe_save_output(output: Dict[str, Any], output_path: str | Path | None) -> None:
    if output_path is None:
        return

    path = Path(output_path)
    path.parent.mkdir(parents=True, exist_ok=True)

    with path.open("w", encoding="utf-8") as f:
        json.dump(output, f, indent=2, ensure_ascii=False)


def load_problem_context(
    *,
    problem_id: str | None,
    problem_name: str | None,
    problem_description_file: str | None,
    sample_tests_file: str | None,
) -> ProblemContext | None:
    if not any([problem_id, problem_name, problem_description_file, sample_tests_file]):
        return None

    description = ""
    if problem_description_file:
        description = read_text_file(problem_description_file)

    sample_tests = []
    if sample_tests_file:
        sample_tests = read_json_file(sample_tests_file)

    return ProblemContext(
        problem_id=problem_id or "",
        problem_name=problem_name or "",
        problem_description=description,
        sample_tests=sample_tests,
    )


def verification_to_dict(verification) -> Dict[str, Any]:
    return {
        "compile_success": verification.compile_success,
        "compile_stdout": verification.compile_stdout,
        "compile_stderr": verification.compile_stderr,
        "all_tests_passed": verification.all_tests_passed,
        "test_results": [
            {
                "input": test.input,
                "expected_output": test.expected_output,
                "actual_output": test.actual_output,
                "passed": test.passed,
                "stderr": test.stderr,
                "timed_out": test.timed_out,
                "return_code": test.return_code,
            }
            for test in verification.test_results
        ],
    }


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Generate translated C++ code with retrieval and optional verification."
    )

    parser.add_argument("--source-file", required=True)
    parser.add_argument("--index", required=True)
    parser.add_argument("--meta", required=True)

    parser.add_argument(
        "--model",
        required=True,
        help="Full model path/name or LoRA adapter path.",
    )
    parser.add_argument(
        "--base-model",
        default=None,
        help="Base model name if --model is a LoRA adapter.",
    )

    parser.add_argument("--top-k", type=int, default=3)
    parser.add_argument("--problem-id", default=None)
    parser.add_argument("--problem-name", default=None)
    parser.add_argument("--problem-description-file", default=None)
    parser.add_argument("--sample-tests-file", default=None)

    parser.add_argument("--max-new-tokens", type=int, default=1024)
    parser.add_argument("--temperature", type=float, default=0.0)
    parser.add_argument("--top-p", type=float, default=1.0)
    parser.add_argument("--do-sample", action="store_true")

    parser.add_argument(
        "--torch-dtype",
        default="bfloat16",
        choices=["auto", "float16", "bfloat16", "float32"],
    )

    parser.add_argument("--output", default=None)
    parser.add_argument("--verify", action="store_true")
    parser.add_argument("--repair-rounds", type=int, default=0)
    parser.add_argument("--compiler", default="g++")

    args = parser.parse_args()

    source_code = read_text_file(args.source_file)

    problem_context = load_problem_context(
        problem_id=args.problem_id,
        problem_name=args.problem_name,
        problem_description_file=args.problem_description_file,
        sample_tests_file=args.sample_tests_file,
    )

    searcher = CodeSearcher(
        index_path=args.index,
        metadata_path=args.meta,
    )

    retrieved_examples = searcher.search(
        query_code=source_code,
        top_k=args.top_k,
        problem_id=problem_context.problem_id if problem_context else args.problem_id,
        problem_name=problem_context.problem_name if problem_context else args.problem_name,
        problem_description=problem_context.problem_description if problem_context else None,
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

    translator = CodeTranslator(
        model_name=args.model,
        base_model=args.base_model,
        torch_dtype=args.torch_dtype,
    )

    generation = translator.generate(
        source_code=source_code,
        retrieved_examples=retrieved_examples,
        problem_context=problem_context,
        constraints=constraints,
        max_new_tokens=args.max_new_tokens,
        temperature=args.temperature,
        top_p=args.top_p,
        do_sample=args.do_sample,
    )

    current_code = generation["generated_code"]

    output: Dict[str, Any] = {
        "retrieved_examples": retrieved_examples,
        "prompt": generation["prompt"],
        "generated_code": current_code,
        "repair_history": [],
    }

    if args.verify:
        verifier = CppVerifier(compiler=args.compiler)
        sample_tests = problem_context.sample_tests if problem_context else []

        verification = verifier.verify(current_code, sample_tests)

        output["verification"] = verification_to_dict(verification)

        for repair_round in range(args.repair_rounds):
            if verification.all_tests_passed:
                break

            feedback = VerificationFeedback(
                compile_success=verification.compile_success,
                compile_stderr=verification.compile_stderr,
                failed_tests=verification.failed_tests_as_dicts(),
            )

            generation = translator.generate(
                source_code=source_code,
                retrieved_examples=retrieved_examples,
                problem_context=problem_context,
                constraints=constraints,
                previous_attempt=current_code,
                verification_feedback=feedback,
                max_new_tokens=args.max_new_tokens,
                temperature=args.temperature,
                top_p=args.top_p,
                do_sample=args.do_sample,
            )

            current_code = generation["generated_code"]
            verification = verifier.verify(current_code, sample_tests)

            output["repair_history"].append(
                {
                    "round": repair_round + 1,
                    "prompt": generation["prompt"],
                    "generated_code": current_code,
                    "verification": verification_to_dict(verification),
                }
            )

        output["generated_code"] = current_code
        output["final_verification"] = verification_to_dict(verification)

    maybe_save_output(output, args.output)

    print(json.dumps(output, indent=2, ensure_ascii=False))


if __name__ == "__main__":
    main()