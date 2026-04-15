"""
Generation module for retrieval-augmented Python -> C++ translation with verification.

This file:
- builds a CodeNet-aware translation prompt
- retrieves accepted C++ references from the FAISS index
- loads a Hugging Face causal language model
- generates translated target code
- optionally compiles and repairs the result using verifier feedback
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any, Dict, List

import torch
from transformers import AutoModelForCausalLM, AutoTokenizer

from translation.prompt_builder import (
    ProblemContext,
    TranslationConstraints,
    VerificationFeedback,
    build_translation_prompt,
)
from retrieval.search import CodeSearcher
from translation.verifier import CppVerifier


class CodeTranslator:
    """
    Wrapper around a causal LM for CodeNet-grounded code translation.
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

    def generate_from_prompt(
        self,
        prompt: str,
        *,
        max_new_tokens: int = 512,
        temperature: float = 0.2,
        top_p: float = 0.95,
        do_sample: bool = True,
    ) -> str:
        inputs = self.tokenizer(
            prompt,
            return_tensors="pt",
            truncation=True,
            max_length=4096,
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
        return generated_text

    def generate(
        self,
        *,
        source_code: str,
        retrieved_examples: List[Dict[str, Any]],
        problem_context: ProblemContext | None = None,
        constraints: TranslationConstraints | None = None,
        previous_attempt: str | None = None,
        verification_feedback: VerificationFeedback | None = None,
        max_new_tokens: int = 512,
        temperature: float = 0.2,
        top_p: float = 0.95,
        do_sample: bool = True,
    ) -> Dict[str, str]:
        prompt = build_translation_prompt(
            source_code=source_code,
            retrieved_examples=retrieved_examples,
            constraints=constraints,
            problem_context=problem_context,
            previous_attempt=previous_attempt,
            verification_feedback=verification_feedback,
        )
        generated_text = self.generate_from_prompt(
            prompt,
            max_new_tokens=max_new_tokens,
            temperature=temperature,
            top_p=top_p,
            do_sample=do_sample,
        )
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


def main() -> None:
    parser = argparse.ArgumentParser(description="Generate translated C++ code using CodeNet retrieval and verification.")
    parser.add_argument("--source-file", required=True, help="Path to input Python source code file.")
    parser.add_argument("--index", required=True, help="Path to the FAISS index.")
    parser.add_argument("--meta", required=True, help="Path to the retrieval metadata JSON.")
    parser.add_argument("--model", default="bigcode/starcoder2-3b", help="Hugging Face causal LM name.")
    parser.add_argument("--top-k", type=int, default=3, help="Number of accepted references to retrieve.")
    parser.add_argument("--problem-id", default=None, help="Optional CodeNet problem id.")
    parser.add_argument("--problem-name", default=None, help="Optional problem name.")
    parser.add_argument("--problem-description-file", default=None, help="Optional path to problem text.")
    parser.add_argument("--sample-tests-file", default=None, help="Optional path to JSON list of sample tests.")
    parser.add_argument("--max-new-tokens", type=int, default=512, help="Maximum generated tokens.")
    parser.add_argument("--temperature", type=float, default=0.2, help="Sampling temperature.")
    parser.add_argument("--top-p", type=float, default=0.95, help="Nucleus sampling parameter.")
    parser.add_argument("--output", default=None, help="Optional path to save JSON output.")
    parser.add_argument("--verify", action="store_true", help="Compile and run sample tests after generation.")
    parser.add_argument("--repair-rounds", type=int, default=0, help="How many repair rounds to run after the first attempt.")
    parser.add_argument("--compiler", default="g++", help="Compiler to use for verification.")
    args = parser.parse_args()

    source_code = read_text_file(args.source_file)
    problem_context = load_problem_context(
        problem_id=args.problem_id,
        problem_name=args.problem_name,
        problem_description_file=args.problem_description_file,
        sample_tests_file=args.sample_tests_file,
    )

    searcher = CodeSearcher(index_path=args.index, metadata_path=args.meta)
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

    translator = CodeTranslator(model_name=args.model)
    generation = translator.generate(
        source_code=source_code,
        retrieved_examples=retrieved_examples,
        problem_context=problem_context,
        constraints=constraints,
        max_new_tokens=args.max_new_tokens,
        temperature=args.temperature,
        top_p=args.top_p,
        do_sample=True,
    )

    output: Dict[str, Any] = {
        "retrieved_examples": retrieved_examples,
        "prompt": generation["prompt"],
        "generated_code": generation["generated_code"],
        "repair_history": [],
    }

    if args.verify:
        verifier = CppVerifier(compiler=args.compiler)
        current_code = generation["generated_code"]
        verification = verifier.verify(current_code, problem_context.sample_tests if problem_context else [])
        output["verification"] = {
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
                do_sample=True,
            )

            current_code = generation["generated_code"]
            verification = verifier.verify(current_code, problem_context.sample_tests if problem_context else [])

            output["repair_history"].append(
                {
                    "round": repair_round + 1,
                    "prompt": generation["prompt"],
                    "generated_code": current_code,
                    "verification": {
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
                    },
                }
            )

        output["generated_code"] = current_code
        output["final_verification"] = output["repair_history"][-1]["verification"] if output["repair_history"] else output["verification"]

    maybe_save_output(output, args.output)

    print("=" * 80)
    print("RETRIEVED REFERENCES")
    print("=" * 80)
    print(json.dumps(retrieved_examples, indent=2, ensure_ascii=False))
    print()
    print("=" * 80)
    print("PROMPT")
    print("=" * 80)
    print(output["prompt"])
    print()
    print("=" * 80)
    print("GENERATED CODE")
    print("=" * 80)
    print(output["generated_code"])
    if args.verify:
        print()
        print("=" * 80)
        print("FINAL VERIFICATION")
        print("=" * 80)
        print(json.dumps(output["final_verification"], indent=2, ensure_ascii=False))


if __name__ == "__main__":
    main()
