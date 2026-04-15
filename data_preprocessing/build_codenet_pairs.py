"""
Build weak Python -> C++ translation pairs from Project CodeNet.

Because CodeNet is organized by problem and language rather than exact translation
pairs, this script constructs weakly aligned pairs from accepted submissions that
solve the same problem.
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Dict, List

from data_preprocessing.codenet_loader import (
    get_problem_description_text,
    get_problem_sample_tests,
    iter_problem_submissions,
    load_problem_catalog,
    load_submission_code,
    SubmissionRecord,
)


def _submission_sort_key(record: SubmissionRecord) -> tuple:
    cpu = record.cpu_time if record.cpu_time is not None and record.cpu_time >= 0 else 10**12
    mem = record.memory if record.memory is not None and record.memory >= 0 else 10**12
    size = record.code_size if record.code_size is not None and record.code_size >= 0 else 10**12
    return (cpu, mem, size, record.submission_id)


def build_pair_record(
    problem_name: str,
    problem_description: str,
    sample_tests: List[Dict[str, str]],
    source_record: SubmissionRecord,
    target_record: SubmissionRecord,
) -> Dict[str, object]:
    source_code = load_submission_code(source_record)
    target_code = load_submission_code(target_record)

    return {
        "id": f"{source_record.problem_id}__{source_record.submission_id}__{target_record.submission_id}",
        "problem_id": source_record.problem_id,
        "problem_name": problem_name,
        "problem_description": problem_description,
        "sample_tests": sample_tests,
        "source_lang": source_record.language,
        "target_lang": target_record.language,
        "source_submission_id": source_record.submission_id,
        "target_submission_id": target_record.submission_id,
        "source_code": source_code,
        "target_code": target_code,
        "source_path": source_record.source_path,
        "target_path": target_record.source_path,
        "source_cpu_time": source_record.cpu_time,
        "target_cpu_time": target_record.cpu_time,
        "source_memory": source_record.memory,
        "target_memory": target_record.memory,
        "source_code_size": source_record.code_size,
        "target_code_size": target_record.code_size,
        "tags": [],
    }


def main() -> None:
    parser = argparse.ArgumentParser(description="Build weak Python -> C++ pairs from Project CodeNet.")
    parser.add_argument("--codenet-root", required=True, help="Path to the Project CodeNet root.")
    parser.add_argument("--output", required=True, help="Where to write the output JSONL.")
    parser.add_argument("--source-lang", default="Python", help="Source language to select.")
    parser.add_argument("--target-lang", default="C++", help="Target language to select.")
    parser.add_argument("--max-problems", type=int, default=None, help="Optional cap on number of problems processed.")
    parser.add_argument("--max-source-per-problem", type=int, default=3, help="How many source solutions to keep per problem.")
    parser.add_argument("--max-target-per-problem", type=int, default=3, help="How many target references to keep per problem.")
    parser.add_argument(
        "--pairing",
        choices=["cartesian", "best_target_per_source"],
        default="best_target_per_source",
        help="Pairing strategy for source and target submissions.",
    )
    parser.add_argument("--max-code-size", type=int, default=50000, help="Discard overly large source files.")
    args = parser.parse_args()

    catalog = load_problem_catalog(args.codenet_root)
    problem_ids = sorted(catalog.keys())
    if args.max_problems is not None:
        problem_ids = problem_ids[: args.max_problems]

    output_path = Path(args.output)
    output_path.parent.mkdir(parents=True, exist_ok=True)

    total_pairs = 0
    problems_with_pairs = 0

    with output_path.open("w", encoding="utf-8") as out:
        for problem_id in problem_ids:
            source_records = list(
                iter_problem_submissions(
                    args.codenet_root,
                    problem_id,
                    languages=[args.source_lang],
                    accepted_only=True,
                    load_code=False,
                    max_code_size=args.max_code_size,
                )
            )
            target_records = list(
                iter_problem_submissions(
                    args.codenet_root,
                    problem_id,
                    languages=[args.target_lang],
                    accepted_only=True,
                    load_code=False,
                    max_code_size=args.max_code_size,
                )
            )

            if not source_records or not target_records:
                continue

            source_records.sort(key=_submission_sort_key)
            target_records.sort(key=_submission_sort_key)

            source_records = source_records[: args.max_source_per_problem]
            target_records = target_records[: args.max_target_per_problem]

            problem_name = catalog[problem_id].name if problem_id in catalog else ""
            problem_description = get_problem_description_text(args.codenet_root, problem_id)
            sample_tests = get_problem_sample_tests(args.codenet_root, problem_id)

            pair_records: List[Dict[str, object]] = []

            if args.pairing == "cartesian":
                for source_record in source_records:
                    for target_record in target_records:
                        pair_records.append(
                            build_pair_record(
                                problem_name,
                                problem_description,
                                sample_tests,
                                source_record,
                                target_record,
                            )
                        )
            else:
                best_target = target_records[0]
                for source_record in source_records:
                    pair_records.append(
                        build_pair_record(
                            problem_name,
                            problem_description,
                            sample_tests,
                            source_record,
                            best_target,
                        )
                    )

            for pair in pair_records:
                out.write(json.dumps(pair, ensure_ascii=False) + "\n")

            total_pairs += len(pair_records)
            problems_with_pairs += 1

    print(f"Wrote {total_pairs} weak pairs across {problems_with_pairs} problems to {output_path}")


if __name__ == "__main__":
    main()
