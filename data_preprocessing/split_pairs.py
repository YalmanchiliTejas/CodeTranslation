from __future__ import annotations

import argparse
import json
import random
from collections import defaultdict
from pathlib import Path
from typing import Dict, List


def load_jsonl(path: Path) -> List[Dict]:
    if not path.exists():
        raise FileNotFoundError(f"Input file not found: {path}")

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

    if not records:
        raise ValueError(f"No records found in {path}")

    return records


def write_jsonl(records: List[Dict], path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)

    with path.open("w", encoding="utf-8") as f:
        for record in records:
            f.write(json.dumps(record, ensure_ascii=False) + "\n")


def split_by_problem(
    records: List[Dict],
    train_ratio: float,
    valid_ratio: float,
    seed: int,
) -> tuple[List[Dict], List[Dict], List[Dict]]:
    if train_ratio <= 0:
        raise ValueError("train_ratio must be > 0.")

    if valid_ratio < 0:
        raise ValueError("valid_ratio must be >= 0.")

    if train_ratio + valid_ratio >= 1:
        raise ValueError("train_ratio + valid_ratio must be < 1.")

    by_problem = defaultdict(list)

    for record in records:
        problem_id = record.get("problem_id")

        if not problem_id:
            raise KeyError("Every record must contain problem_id.")

        by_problem[problem_id].append(record)

    problem_ids = sorted(by_problem.keys())

    rng = random.Random(seed)
    rng.shuffle(problem_ids)

    total_problems = len(problem_ids)
    n_train = int(total_problems * train_ratio)
    n_valid = int(total_problems * valid_ratio)

    train_ids = set(problem_ids[:n_train])
    valid_ids = set(problem_ids[n_train:n_train + n_valid])
    test_ids = set(problem_ids[n_train + n_valid:])

    train_records = [record for pid in train_ids for record in by_problem[pid]]
    valid_records = [record for pid in valid_ids for record in by_problem[pid]]
    test_records = [record for pid in test_ids for record in by_problem[pid]]

    return train_records, valid_records, test_records


def count_with_tests(records: List[Dict]) -> int:
    return sum(1 for record in records if record.get("sample_tests"))


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Split Python -> C++ weak-pair JSONL into train/valid/test by problem_id."
    )

    parser.add_argument(
        "--input",
        required=True,
        help="Input JSONL file, for example data/python_cpp_pairs.jsonl.",
    )
    parser.add_argument(
        "--out-dir",
        default="data",
        help="Output directory for train.jsonl, valid.jsonl, and test.jsonl.",
    )
    parser.add_argument("--train-ratio", type=float, default=0.8)
    parser.add_argument("--valid-ratio", type=float, default=0.1)
    parser.add_argument("--seed", type=int, default=42)

    args = parser.parse_args()

    input_path = Path(args.input)
    out_dir = Path(args.out_dir)

    records = load_jsonl(input_path)

    train, valid, test = split_by_problem(
        records=records,
        train_ratio=args.train_ratio,
        valid_ratio=args.valid_ratio,
        seed=args.seed,
    )

    write_jsonl(train, out_dir / "train.jsonl")
    write_jsonl(valid, out_dir / "valid.jsonl")
    write_jsonl(test, out_dir / "test.jsonl")

    print("Split complete.")
    print(f"Input records: {len(records)}")
    print(f"Train records: {len(train)} | with sample_tests: {count_with_tests(train)}")
    print(f"Valid records: {len(valid)} | with sample_tests: {count_with_tests(valid)}")
    print(f"Test records:  {len(test)} | with sample_tests: {count_with_tests(test)}")
    print(f"Wrote: {out_dir / 'train.jsonl'}")
    print(f"Wrote: {out_dir / 'valid.jsonl'}")
    print(f"Wrote: {out_dir / 'test.jsonl'}")


if __name__ == "__main__":
    main()