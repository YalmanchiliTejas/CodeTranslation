"""
Search a FAISS code-retrieval index for the top-k similar examples.

Example:
    python search.py \
        --index retriever/artifacts/code_index.faiss \
        --meta retriever/artifacts/metadata.json \
        --query "def sum_even(nums): return [x for x in nums if x % 2 == 0]" \
        --top-k 3
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any, Dict, List

import faiss

from embedder import CodeEmbedder


class CodeSearcher:
    def __init__(
        self,
        index_path: str | Path,
        metadata_path: str | Path,
        model_name: str = "microsoft/codebert-base",
    ) -> None:
        self.index_path = Path(index_path)
        self.metadata_path = Path(metadata_path)

        if not self.index_path.exists():
            raise FileNotFoundError(f"FAISS index not found: {self.index_path}")
        if not self.metadata_path.exists():
            raise FileNotFoundError(f"Metadata file not found: {self.metadata_path}")

        self.index = faiss.read_index(str(self.index_path))

        with self.metadata_path.open("r", encoding="utf-8") as f:
            self.metadata: List[Dict[str, Any]] = json.load(f)

        if self.index.ntotal != len(self.metadata):
            raise ValueError(
                f"Index size ({self.index.ntotal}) does not match metadata size ({len(self.metadata)})."
            )

        self.embedder = CodeEmbedder()

    def search(self, query_code: str, top_k: int = 3) -> List[Dict[str, Any]]:
        if not isinstance(query_code, str) or not query_code.strip():
            raise ValueError("query_code must be a non-empty string.")
        if top_k <= 0:
            raise ValueError("top_k must be positive.")

        query_vector = self.embedder.embed_text(query_code).reshape(1, -1)
        scores, indices = self.index.search(query_vector, top_k)

        results: List[Dict[str, Any]] = []
        for score, idx in zip(scores[0], indices[0]):
            if idx == -1:
                continue

            item = dict(self.metadata[idx])
            item["score"] = float(score)
            results.append(item)

        return results


def pretty_print(results: List[Dict[str, Any]]) -> None:
    if not results:
        print("No results found.")
        return

    for rank, item in enumerate(results, start=1):
        print("=" * 80)
        print(f"Rank: {rank}")
        print(f"ID: {item['id']}")
        print(f"Score: {item['score']:.4f}")
        print(f"Tags: {item.get('tags', [])}")
        print("\n[Retrieved Source]")
        print(item["source_code"])
        print("\n[Retrieved Target]")
        print(item["target_code"])
        print()


def main() -> None:
    parser = argparse.ArgumentParser(description="Search a FAISS retrieval index for similar code examples.")
    parser.add_argument("--index", required=True, help="Path to the FAISS index.")
    parser.add_argument("--meta", required=True, help="Path to the metadata JSON.")
    parser.add_argument("--query", required=True, help="Source code query string.")
    parser.add_argument("--top-k", type=int, default=3, help="Number of nearest examples to retrieve.")
    args = parser.parse_args()

    searcher = CodeSearcher(
        index_path=args.index,
        metadata_path=args.meta,
    )
    results = searcher.search(args.query, top_k=args.top_k)
    pretty_print(results)


if __name__ == "__main__":
    main()
