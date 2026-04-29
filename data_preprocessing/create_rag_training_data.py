from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any, Dict, List

from retrieval.search import CodeSearcher


def load_jsonl(path: str | Path) -> List[Dict[str, Any]]:
    path = Path(path)

    if not path.exists():
        raise FileNotFoundError(f"Input file not found: {path}")

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
        raise ValueError(f"No records found in: {path}")

    return records


def write_jsonl(records: List[Dict[str, Any]], path: str | Path) -> None:
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)

    with path.open("w", encoding="utf-8") as f:
        for record in records:
            f.write(json.dumps(record, ensure_ascii=False) + "\n")


def add_retrieval_to_records(
    records: List[Dict[str, Any]],
    searcher: CodeSearcher,
    top_k: int,
) -> List[Dict[str, Any]]:
    augmented: List[Dict[str, Any]] = []

    for idx, record in enumerate(records, start=1):
        record_id = record.get("id")

        # Retrieve extra candidates because we remove self-matches.
        # The searcher now uses problem description + sample tests + source code.
        retrieved = searcher.search(
            query_code=record["source_code"],
            top_k=top_k + 10,
            problem_id=record.get("problem_id", ""),
            problem_name=record.get("problem_name", ""),
            problem_description=record.get("problem_description", ""),
            sample_tests=record.get("sample_tests", []),
            same_problem_first=False,
        )

        filtered: List[Dict[str, Any]] = []

        for item in retrieved:
            # Avoid giving the exact same pair to itself during training.
            if item.get("id") == record_id:
                continue

            # Avoid retrieving the same target submission if possible.
            if (
                item.get("target_submission_id")
                and record.get("target_submission_id")
                and item.get("target_submission_id") == record.get("target_submission_id")
            ):
                continue

            filtered.append(item)

            if len(filtered) >= top_k:
                break

        new_record = dict(record)
        new_record["retrieved_examples"] = filtered
        augmented.append(new_record)

        retrieved_ids = [item.get("id") for item in filtered]
        retrieved_pids = [item.get("problem_id") for item in filtered]

        print(
            f"[{idx}/{len(records)}] id={record_id} "
            f"problem={record.get('problem_id')} "
            f"retrieved={len(filtered)} "
            f"retrieved_pids={retrieved_pids} "
            f"retrieved_ids={retrieved_ids}"
        )

    return augmented


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Add problem-aware CodeBERT-retrieved examples to train/valid JSONL records."
    )

    parser.add_argument("--input", required=True, help="Input JSONL, e.g. data/train.jsonl")
    parser.add_argument("--output", required=True, help="Output JSONL, e.g. data/train_rag_k1.jsonl")
    parser.add_argument("--index", required=True, help="FAISS index path.")
    parser.add_argument("--meta", required=True, help="Retrieval metadata JSON.")
    parser.add_argument("--top-k", type=int, default=1)

    args = parser.parse_args()

    if args.top_k < 0:
        raise ValueError("--top-k must be >= 0.")

    records = load_jsonl(args.input)

    searcher = CodeSearcher(
        index_path=args.index,
        metadata_path=args.meta,
    )

    augmented = add_retrieval_to_records(
        records=records,
        searcher=searcher,
        top_k=args.top_k,
    )

    write_jsonl(augmented, args.output)

    with_retrieval = sum(1 for r in augmented if r.get("retrieved_examples"))

    print("Done.")
    print(f"Input records: {len(records)}")
    print(f"Output records: {len(augmented)}")
    print(f"Records with retrieved examples: {with_retrieval}")
    print(f"Wrote: {args.output}")


if __name__ == "__main__":
    main()