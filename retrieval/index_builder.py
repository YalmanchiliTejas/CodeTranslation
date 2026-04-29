"""
Build a FAISS vector index over CodeNet-aware weak translation pairs.

This version builds problem-aware retrieval text using:
- problem_id
- problem_name
- problem_description
- sample_tests
- source_code

This helps avoid retrieving syntactically similar but semantically unrelated problems.
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any, Dict, List

import faiss
import numpy as np

from retrieval.embedder import CodeEmbedder, EmbedderConfig


def load_examples(input_path: str | Path) -> List[Dict[str, Any]]:
    path = Path(input_path)
    if not path.exists():
        raise FileNotFoundError(f"Input file not found: {path}")

    if path.suffix.lower() == ".jsonl":
        examples: List[Dict[str, Any]] = []
        with path.open("r", encoding="utf-8") as f:
            for line_num, line in enumerate(f, start=1):
                line = line.strip()
                if not line:
                    continue
                try:
                    examples.append(json.loads(line))
                except json.JSONDecodeError as e:
                    raise ValueError(f"Invalid JSON on line {line_num}: {e}") from e
        return examples

    with path.open("r", encoding="utf-8") as f:
        data = json.load(f)

    if not isinstance(data, list):
        raise ValueError("Input JSON must contain a top-level list of examples.")

    return data


def validate_examples(examples: List[Dict[str, Any]]) -> None:
    if not examples:
        raise ValueError("No examples found in the input data.")

    required = {"id", "source_code", "target_code", "problem_id"}

    for i, ex in enumerate(examples):
        missing = required - set(ex.keys())
        if missing:
            raise ValueError(
                f"Example at index {i} is missing required fields: {sorted(missing)}"
            )

        if not isinstance(ex["source_code"], str) or not ex["source_code"].strip():
            raise ValueError(f"Example at index {i} has empty source_code.")

        if not isinstance(ex["target_code"], str) or not ex["target_code"].strip():
            raise ValueError(f"Example at index {i} has empty target_code.")


def _clip(text: str | None, max_chars: int) -> str:
    text = (text or "").strip()

    if max_chars <= 0:
        return ""

    if len(text) <= max_chars:
        return text

    return text[:max_chars].rstrip() + "\n...[truncated]"


def format_sample_tests(sample_tests: Any, max_tests: int = 1, max_chars: int = 500) -> str:
    if not sample_tests:
        return ""

    if not isinstance(sample_tests, list):
        return ""

    parts: List[str] = []

    for idx, test in enumerate(sample_tests[:max_tests], start=1):
        if not isinstance(test, dict):
            continue

        sample_input = _clip(test.get("input", ""), max_chars)
        sample_output = _clip(test.get("output", ""), max_chars)

        if sample_input or sample_output:
            parts.append(f"Sample Input {idx}:\n{sample_input}")
            parts.append(f"Sample Output {idx}:\n{sample_output}")

    return "\n".join(parts).strip()


def build_problem_aware_retrieval_text(
    example: Dict[str, Any],
    *,
    max_problem_chars: int = 600,
    max_code_chars: int = 1200,
    max_sample_chars: int = 500,
    max_sample_tests: int = 1,
) -> str:
    """
    Build the text that gets embedded into FAISS.

    Important:
    Retrieval should not be based only on Python syntax. Competitive-programming
    code often looks similar even when the algorithms are unrelated. So we include
    compact problem context and sample I/O.
    """
    parts: List[str] = []

    problem_id = example.get("problem_id", "")
    problem_name = example.get("problem_name", "")

    if problem_id:
        parts.append(f"Problem ID:\n{problem_id}")

    if problem_name:
        parts.append(f"Problem Name:\n{problem_name}")

    problem_description = _clip(
        example.get("problem_description", ""),
        max_problem_chars,
    )

    if problem_description:
        parts.append(f"Problem Description:\n{problem_description}")

    sample_text = format_sample_tests(
        example.get("sample_tests", []),
        max_tests=max_sample_tests,
        max_chars=max_sample_chars,
    )

    if sample_text:
        parts.append(f"Sample Tests:\n{sample_text}")

    source_code = _clip(example.get("source_code", ""), max_code_chars)
    parts.append(f"Python Source Code:\n{source_code}")

    return "\n\n".join(parts).strip()


def build_index(
    examples: List[Dict[str, Any]],
    model_name: str = "microsoft/codebert-base",
    batch_size: int = 16,
    max_problem_chars: int = 600,
    max_code_chars: int = 1200,
) -> tuple[faiss.Index, List[Dict[str, Any]]]:
    embedder = CodeEmbedder(
        config=EmbedderConfig(
            model_name=model_name,
            problem_text_chars=max_problem_chars,
        )
    )

    source_chunks = [
        build_problem_aware_retrieval_text(
            ex,
            max_problem_chars=max_problem_chars,
            max_code_chars=max_code_chars,
            max_sample_chars=500,
            max_sample_tests=1,
        )
        for ex in examples
    ]

    embeddings = embedder.embed_batch(source_chunks, batch_size=batch_size)

    if embeddings.dtype != np.float32:
        embeddings = embeddings.astype(np.float32)

    dimension = embeddings.shape[1]
    index = faiss.IndexFlatIP(dimension)
    index.add(embeddings)

    metadata: List[Dict[str, Any]] = []

    for ex in examples:
        metadata.append(
            {
                "id": ex["id"],
                "problem_id": ex.get("problem_id"),
                "problem_name": ex.get("problem_name", ""),
                "problem_description": ex.get("problem_description", ""),
                "sample_tests": ex.get("sample_tests", []),
                "source_code": ex["source_code"],
                "target_code": ex["target_code"],
                "tags": ex.get("tags", []),
                "source_lang": ex.get("source_lang", "Python"),
                "target_lang": ex.get("target_lang", "C++"),
                "source_submission_id": ex.get("source_submission_id"),
                "target_submission_id": ex.get("target_submission_id"),
                "source_path": ex.get("source_path"),
                "target_path": ex.get("target_path"),
                "source_cpu_time": ex.get("source_cpu_time"),
                "target_cpu_time": ex.get("target_cpu_time"),
                "source_memory": ex.get("source_memory"),
                "target_memory": ex.get("target_memory"),
            }
        )

    return index, metadata


def save_index(
    index: faiss.Index,
    metadata: List[Dict[str, Any]],
    index_out: str | Path,
    meta_out: str | Path,
) -> None:
    index_path = Path(index_out)
    meta_path = Path(meta_out)

    index_path.parent.mkdir(parents=True, exist_ok=True)
    meta_path.parent.mkdir(parents=True, exist_ok=True)

    faiss.write_index(index, str(index_path))

    with meta_path.open("w", encoding="utf-8") as f:
        json.dump(metadata, f, indent=2, ensure_ascii=False)


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Build a problem-aware FAISS retrieval index for CodeNet weak pairs."
    )

    parser.add_argument("--input", required=True, help="Path to JSON or JSONL weak-pair file.")
    parser.add_argument("--index-out", required=True, help="Where to save the FAISS index.")
    parser.add_argument("--meta-out", required=True, help="Where to save metadata JSON.")
    parser.add_argument("--model-name", default="microsoft/codebert-base", help="Embedding model name.")
    parser.add_argument("--batch-size", type=int, default=16, help="Embedding batch size.")
    parser.add_argument(
        "--max-problem-chars",
        type=int,
        default=600,
        help="Maximum problem-description characters used during embedding.",
    )
    parser.add_argument(
        "--max-code-chars",
        type=int,
        default=1200,
        help="Maximum Python source-code characters used during embedding.",
    )

    args = parser.parse_args()

    examples = load_examples(args.input)
    validate_examples(examples)

    index, metadata = build_index(
        examples=examples,
        model_name=args.model_name,
        batch_size=args.batch_size,
        max_problem_chars=args.max_problem_chars,
        max_code_chars=args.max_code_chars,
    )

    save_index(index, metadata, args.index_out, args.meta_out)

    print(f"Built problem-aware index with {len(metadata)} examples.")
    print(f"Saved FAISS index to: {args.index_out}")
    print(f"Saved metadata to: {args.meta_out}")


if __name__ == "__main__":
    main()