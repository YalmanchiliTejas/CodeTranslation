from __future__ import annotations

import argparse
import csv
from pathlib import Path


def create_problem_list(codenet_root: str | Path) -> None:
    root = Path(codenet_root)

    data_dir = root / "data"
    metadata_dir = root / "metadata"
    output_path = metadata_dir / "problem_list.csv"

    if not root.exists():
        raise FileNotFoundError(f"CodeNet root not found: {root}")

    if not data_dir.exists():
        raise FileNotFoundError(f"Data directory not found: {data_dir}")

    metadata_dir.mkdir(parents=True, exist_ok=True)

    problem_ids = sorted(
        path.name
        for path in data_dir.iterdir()
        if path.is_dir() and path.name.startswith("p")
    )

    if not problem_ids:
        raise ValueError(f"No problem folders found inside: {data_dir}")

    fieldnames = [
        "id",
        "name",
        "dataset",
        "time_limit",
        "memory_limit",
        "rating",
        "tags",
        "complexity",
    ]

    with output_path.open("w", encoding="utf-8", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()

        for problem_id in problem_ids:
            writer.writerow(
                {
                    "id": problem_id,
                    "name": problem_id,
                    "dataset": "Project_CodeNet",
                    "time_limit": "",
                    "memory_limit": "",
                    "rating": "",
                    "tags": "",
                    "complexity": "",
                }
            )

    print(f"Wrote {len(problem_ids)} problems to: {output_path}")


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Create a minimal problem_list.csv for a cleaned/subset CodeNet dataset."
    )
    parser.add_argument(
        "--codenet-root",
        required=True,
        help="Path to the CodeNet root folder containing data/ and metadata/.",
    )

    args = parser.parse_args()
    create_problem_list(args.codenet_root)


if __name__ == "__main__":
    main()