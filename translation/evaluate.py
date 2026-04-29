"""
Batch evaluation for the retrieval-augmented Python -> C++ pipeline.

For each example:
1. retrieve accepted Python/C++ references,
2. generate C++ with base model or LoRA adapter,
3. compile generated C++,
4. run sample tests if available,
5. optionally repair using compiler/test feedback.

Important:
- --top-k 0 disables retrieval.
- sample_tests are passed into retrieval so search is problem-aware.
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any, Dict, Iterable, List

from retrieval.index_builder import load_examples
from retrieval.search import CodeSearcher
from translation.generate import CodeTranslator
from translation.prompt_builder import (
    ProblemContext,
    TranslationConstraints,
    VerificationFeedback,
)
from translation.verifier import CppVerifier


def iter_examples(path: str | Path) -> Iterable[Dict[str, Any]]:
    examples = load_examples(path)
    for example in examples:
        yield example


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


def get_retrieved_examples(
    *,
    searcher: CodeSearcher,
    example: Dict[str, Any],
    problem_context: ProblemContext,
    top_k: int,
) -> List[Dict[str, Any]]:
    if top_k <= 0:
        return []

    return searcher.search(
        query_code=example["source_code"],
        top_k=top_k,
        problem_id=problem_context.problem_id,
        problem_name=problem_context.problem_name,
        problem_description=problem_context.problem_description,
        sample_tests=problem_context.sample_tests,
        same_problem_first=False,
    )


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Evaluate RAG + verification Python -> C++ pipeline."
    )

    parser.add_argument("--dataset", required=True, help="JSON/JSONL test set.")
    parser.add_argument("--index", required=True, help="FAISS index path.")
    parser.add_argument("--meta", required=True, help="Retrieval metadata JSON.")

    parser.add_argument(
        "--model",
        required=True,
        help="Full model path/name or LoRA adapter path.",
    )
    parser.add_argument(
        "--base-model",
        default=None,
        help="Base model name if --model is a LoRA adapter, e.g. bigcode/starcoder2-3b.",
    )

    parser.add_argument("--top-k", type=int, default=1)
    parser.add_argument("--repair-rounds", type=int, default=0)
    parser.add_argument("--max-examples", type=int, default=None)

    parser.add_argument("--results-out", required=True)
    parser.add_argument("--summary-out", required=True)

    parser.add_argument("--compiler", default="g++")
    parser.add_argument("--max-new-tokens", type=int, default=512)
    parser.add_argument("--temperature", type=float, default=0.0)
    parser.add_argument("--top-p", type=float, default=1.0)
    parser.add_argument("--do-sample", action="store_true")

    parser.add_argument(
        "--torch-dtype",
        default="bfloat16",
        choices=["auto", "float16", "bfloat16", "float32"],
    )

    args = parser.parse_args()

    searcher = CodeSearcher(
        index_path=args.index,
        metadata_path=args.meta,
    )

    translator = CodeTranslator(
        model_name=args.model,
        base_model=args.base_model,
        torch_dtype=args.torch_dtype,
    )

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
    summary_path = Path(args.summary_out)

    results_path.parent.mkdir(parents=True, exist_ok=True)
    summary_path.parent.mkdir(parents=True, exist_ok=True)

    total = 0

    initial_compile_successes = 0
    final_compile_successes = 0

    examples_with_sample_tests = 0
    initial_sample_test_passes = 0
    final_sample_test_passes = 0

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

            retrieved_examples = get_retrieved_examples(
                searcher=searcher,
                example=example,
                problem_context=problem_context,
                top_k=args.top_k,
            )

            generation = translator.generate(
                source_code=example["source_code"],
                retrieved_examples=retrieved_examples,
                problem_context=problem_context,
                constraints=constraints,
                max_new_tokens=args.max_new_tokens,
                temperature=args.temperature,
                top_p=args.top_p,
                do_sample=args.do_sample,
            )

            current_code = generation["generated_code"]

            verification = verifier.verify(
                current_code,
                problem_context.sample_tests,
            )

            initial_verification = verification
            initial_compile_success = initial_verification.compile_success
            initial_tests_passed = initial_verification.all_tests_passed

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
                    do_sample=args.do_sample,
                )

                current_code = generation["generated_code"]

                verification = verifier.verify(
                    current_code,
                    problem_context.sample_tests,
                )

                repair_history.append(
                    {
                        "round": repair_round + 1,
                        "generated_code": current_code,
                        "verification": verification_to_dict(verification),
                    }
                )

            if initial_compile_success:
                initial_compile_successes += 1

            if verification.compile_success:
                final_compile_successes += 1

            if problem_context.sample_tests:
                examples_with_sample_tests += 1

                if initial_tests_passed:
                    initial_sample_test_passes += 1

                if verification.all_tests_passed:
                    final_sample_test_passes += 1

            record = {
                "id": example.get("id"),
                "problem_id": example.get("problem_id"),
                "source_submission_id": example.get("source_submission_id"),
                "target_submission_id": example.get("target_submission_id"),
                "retrieved_ids": [item.get("id") for item in retrieved_examples],
                "retrieved_problem_ids": [item.get("problem_id") for item in retrieved_examples],
                "retrieved_scores": [
                    {
                        "id": item.get("id"),
                        "problem_id": item.get("problem_id"),
                        "score": item.get("score"),
                        "rerank_score": item.get("rerank_score"),
                        "desc_overlap_score": item.get("desc_overlap_score"),
                        "sample_overlap_score": item.get("sample_overlap_score"),
                    }
                    for item in retrieved_examples
                ],
                "source_code": example["source_code"],
                "reference_code": example.get("target_code", ""),
                "generated_code": current_code,
                "initial_compile_success": initial_compile_success,
                "initial_tests_passed": initial_tests_passed,
                "initial_verification": verification_to_dict(initial_verification),
                "final_verification": verification_to_dict(verification),
                "repair_history": repair_history,
            }

            out.write(json.dumps(record, ensure_ascii=False) + "\n")
            out.flush()

            print(
                f"[{total}] id={example.get('id')} "
                f"problem={example.get('problem_id')} "
                f"retrieved_pids={[item.get('problem_id') for item in retrieved_examples]} "
                f"initial_compile={initial_compile_success} "
                f"final_compile={verification.compile_success} "
                f"final_tests={verification.all_tests_passed}"
            )

    summary = {
        "total_examples": total,
        "model": args.model,
        "base_model": args.base_model,
        "top_k": args.top_k,
        "repair_rounds": args.repair_rounds,

        "initial_compile_successes": initial_compile_successes,
        "initial_compile_rate": (
            initial_compile_successes / total if total else 0.0
        ),

        "final_compile_successes": final_compile_successes,
        "final_compile_rate": (
            final_compile_successes / total if total else 0.0
        ),

        "examples_with_sample_tests": examples_with_sample_tests,

        "initial_sample_test_passes": initial_sample_test_passes,
        "initial_sample_test_pass_rate": (
            initial_sample_test_passes / examples_with_sample_tests
            if examples_with_sample_tests
            else 0.0
        ),

        "final_sample_test_passes": final_sample_test_passes,
        "final_sample_test_pass_rate": (
            final_sample_test_passes / examples_with_sample_tests
            if examples_with_sample_tests
            else 0.0
        ),

        "results_path": str(results_path),
    }

    with summary_path.open("w", encoding="utf-8") as f:
        json.dump(summary, f, indent=2, ensure_ascii=False)

    print(json.dumps(summary, indent=2, ensure_ascii=False))


if __name__ == "__main__":
    main()