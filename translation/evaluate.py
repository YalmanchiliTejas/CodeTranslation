"""
Batch evaluation for the CodeNet translation pipeline.

Input:
- a JSON or JSONL file of weak Python -> C++ pairs
- a retrieval index + metadata
- a generative model

For each example, the evaluator:
1. retrieves accepted C++ references,
2. generates a C++ translation,
3. compiles it,
4. runs available sample tests,
5. optionally runs repair rounds.

The script writes per-example outputs and a summary JSON.
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any, Dict, Iterable, List

from translation.generate import CodeTranslator
from retrieval.index_builder import load_examples
from translation.prompt_builder import ProblemContext, TranslationConstraints, VerificationFeedback
from retrieval.search import CodeSearcher
from translation.verifier import CppVerifier


def iter_examples(path: str | Path) -> Iterable[Dict[str, Any]]:
    examples = load_examples(path)
    for example in examples:
        yield example


def main() -> None:
    parser = argparse.ArgumentParser(description="Evaluate the CodeNet translation pipeline in batch.")
    parser.add_argument("--dataset", required=True, help="JSON or JSONL file of weak CodeNet pairs.")
    parser.add_argument("--index", required=True, help="Path to retrieval FAISS index.")
    parser.add_argument("--meta", required=True, help="Path to retrieval metadata JSON.")
    parser.add_argument("--model", default="bigcode/starcoder2-3b", help="Generative model name.")
    parser.add_argument("--top-k", type=int, default=3, help="Number of retrieved references per example.")
    parser.add_argument("--repair-rounds", type=int, default=1, help="Repair rounds after initial generation.")
    parser.add_argument("--max-examples", type=int, default=None, help="Optional cap on number of examples.")
    parser.add_argument("--results-out", required=True, help="Path to write per-example JSONL results.")
    parser.add_argument("--summary-out", required=True, help="Path to write summary JSON.")
    parser.add_argument("--compiler", default="g++", help="Compiler to use for verification.")
    parser.add_argument("--max-new-tokens", type=int, default=512, help="Maximum generated tokens.")
    parser.add_argument("--temperature", type=float, default=0.2, help="Sampling temperature.")
    parser.add_argument("--top-p", type=float, default=0.95, help="Top-p sampling parameter.")
    args = parser.parse_args()

    searcher = CodeSearcher(index_path=args.index, metadata_path=args.meta)
    translator = CodeTranslator(model_name=args.model)
    verifier = CppVerifier(compiler=args.compiler)

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

    results_path = Path(args.results_out)
    results_path.parent.mkdir(parents=True, exist_ok=True)
    summary_path = Path(args.summary_out)
    summary_path.parent.mkdir(parents=True, exist_ok=True)

    total = 0
    compile_successes = 0
    examples_with_tests = 0
    sample_test_passes = 0

    with results_path.open("w", encoding="utf-8") as out:
        for example in iter_examples(args.dataset):
            if args.max_examples is not None and total >= args.max_examples:
                break

            total += 1

            problem_context = ProblemContext(
                problem_id=example.get("problem_id", ""),
                problem_name=example.get("problem_name", ""),
                problem_description=example.get("problem_description", ""),
                sample_tests=example.get("sample_tests", []),
            )

            retrieved_examples = searcher.search(
                query_code=example["source_code"],
                top_k=args.top_k,
                problem_id=problem_context.problem_id,
                problem_name=problem_context.problem_name,
                problem_description=problem_context.problem_description,
            )

            generation = translator.generate(
                source_code=example["source_code"],
                retrieved_examples=retrieved_examples,
                problem_context=problem_context,
                constraints=constraints,
                max_new_tokens=args.max_new_tokens,
                temperature=args.temperature,
                top_p=args.top_p,
                do_sample=True,
            )

            current_code = generation["generated_code"]
            verification = verifier.verify(current_code, problem_context.sample_tests)

            repair_history: List[Dict[str, Any]] = []

            for repair_round in range(args.repair_rounds):
                if verification.all_tests_passed:
                    break

                feedback = VerificationFeedback(
                    compile_success=verification.compile_success,
                    compile_stderr=verification.compile_stderr,
                    failed_tests=verification.failed_tests_as_dicts(),
                )

                generation = translator.generate(
                    source_code=example["source_code"],
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
                verification = verifier.verify(current_code, problem_context.sample_tests)

                repair_history.append(
                    {
                        "round": repair_round + 1,
                        "generated_code": current_code,
                        "verification": {
                            "compile_success": verification.compile_success,
                            "all_tests_passed": verification.all_tests_passed,
                            "compile_stderr": verification.compile_stderr,
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

            if verification.compile_success:
                compile_successes += 1
            if problem_context.sample_tests:
                examples_with_tests += 1
                if verification.all_tests_passed:
                    sample_test_passes += 1

            record = {
                "id": example.get("id"),
                "problem_id": example.get("problem_id"),
                "source_submission_id": example.get("source_submission_id"),
                "target_submission_id": example.get("target_submission_id"),
                "retrieved_ids": [item["id"] for item in retrieved_examples],
                "generated_code": current_code,
                "verification": {
                    "compile_success": verification.compile_success,
                    "all_tests_passed": verification.all_tests_passed,
                    "compile_stderr": verification.compile_stderr,
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
                "repair_history": repair_history,
            }
            out.write(json.dumps(record, ensure_ascii=False) + "\n")

    summary = {
        "total_examples": total,
        "compile_successes": compile_successes,
        "compile_rate": (compile_successes / total) if total else 0.0,
        "examples_with_sample_tests": examples_with_tests,
        "sample_test_passes": sample_test_passes,
        "sample_test_pass_rate": (sample_test_passes / examples_with_tests) if examples_with_tests else 0.0,
        "results_path": str(results_path),
    }

    with summary_path.open("w", encoding="utf-8") as f:
        json.dump(summary, f, indent=2, ensure_ascii=False)

    print(json.dumps(summary, indent=2, ensure_ascii=False))


if __name__ == "__main__":
    main()
