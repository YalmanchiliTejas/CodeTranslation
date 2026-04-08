"""
Builds a FAISS vector index over source-code chunks.

Expected input format:
- JSON array of dicts, or
- JSONL file with one dict per line

Each record should at least contain:
    {
        "id": "ex_001",
        "source_code": "...",
        "target_code": "..."
    }

Example:
    python index_builder.py \
        --input data/paired_examples.json \
        --index-out retriever/artifacts/code_index.faiss \
        --meta-out retriever/artifacts/metadata.json
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any, Dict, List

import faiss
import numpy as np

from embedder import CodeEmbedder


def load_examples(input_path: str | Path) -> List[Dict[str, Any]]:
    path = Path(input_path)
    if not path.exists():
        raise FileNotFoundError(f"Input file not found: {path}")

    if path.suffix.lower() == ".jsonl":
        with path.open("r", encoding="utf-8") as f:
            return [json.loads(line) for line in f if line.strip()]

    with path.open("r", encoding="utf-8") as f:
        data = json.load(f)

    if not isinstance(data, list):
        raise ValueError("Input JSON must contain a top-level list of examples.")

    return data


def validate_examples(examples: List[Dict[str, Any]]) -> None:
    if not examples:
        raise ValueError("No examples found in the input data.")

    required = {"id", "source_code", "target_code"}
    for i, ex in enumerate(examples):
        missing = required - set(ex.keys())
        if missing:
            raise ValueError(f"Example at index {i} is missing required fields: {sorted(missing)}")
        if not isinstance(ex["source_code"], str) or not ex["source_code"].strip():
            raise ValueError(f"Example at index {i} has empty source_code.")
        if not isinstance(ex["target_code"], str) or not ex["target_code"].strip():
            raise ValueError(f"Example at index {i} has empty target_code.")


def build_index(
    examples: List[Dict[str, Any]],
    model_name: str = "microsoft/codebert-base",
    batch_size: int = 16,
) -> tuple[faiss.Index, List[Dict[str, Any]]]:
    embedder = CodeEmbedder()
    source_chunks = [ex["source_code"] for ex in examples]

    embeddings = embedder.embed_batch(source_chunks, batch_size=batch_size)
    if embeddings.dtype != np.float32:
        embeddings = embeddings.astype(np.float32)

    dimension = embeddings.shape[1]

    # Since vectors are L2-normalized in the embedder, inner product ~= cosine similarity.
    index = faiss.IndexFlatIP(dimension)
    index.add(embeddings)

    metadata = []
    for ex in examples:
        metadata.append(
            {
                "id": ex["id"],
                "source_code": ex["source_code"],
                "target_code": ex["target_code"],
                "tags": ex.get("tags", []),
                "source_lang": ex.get("source_lang", "python"),
                "target_lang": ex.get("target_lang", "cpp"),
            }
        )

    return index, metadata


def save_index(index: faiss.Index, metadata: List[Dict[str, Any]], index_out: str | Path, meta_out: str | Path) -> None:
    index_path = Path(index_out)
    meta_path = Path(meta_out)

    index_path.parent.mkdir(parents=True, exist_ok=True)
    meta_path.parent.mkdir(parents=True, exist_ok=True)

    faiss.write_index(index, str(index_path))

    with meta_path.open("w", encoding="utf-8") as f:
        json.dump(metadata, f, indent=2, ensure_ascii=False)


def main() -> None:
    parser = argparse.ArgumentParser(description="Build a FAISS retrieval index for code chunks.")
    parser.add_argument("--input", required=True, help="Path to JSON or JSONL paired-example file.")
    parser.add_argument("--index-out", required=True, help="Where to save the FAISS index.")
    parser.add_argument("--meta-out", required=True, help="Where to save metadata JSON.")
    parser.add_argument("--batch-size", type=int, default=16, help="Embedding batch size.")
    args = parser.parse_args()

    examples = load_examples(args.input)
    validate_examples(examples)

    index, metadata = build_index(
        examples=examples,
        batch_size=args.batch_size,
    )
    save_index(index, metadata, args.index_out, args.meta_out)

    print(f"Built index with {len(metadata)} examples.")
    print(f"Saved FAISS index to: {args.index_out}")
    print(f"Saved metadata to: {args.meta_out}")


if __name__ == "__main__":
    main()
