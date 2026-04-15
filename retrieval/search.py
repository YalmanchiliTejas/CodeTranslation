"""
Search a FAISS CodeNet retrieval index for top-k similar accepted references.

This version supports optional task-aware querying using CodeNet problem context.
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any, Dict, List

import faiss

from retrieval.embedder import CodeEmbedder, EmbedderConfig, build_retrieval_text


class CodeSearcher:
    def __init__(
        self,
        index_path: str | Path,
        metadata_path: str | Path,
        model_name: str = "microsoft/codebert-base",
        max_problem_chars: int = 1600,
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

        self.embedder = CodeEmbedder(
            config=EmbedderConfig(
                model_name=model_name,
                problem_text_chars=max_problem_chars,
            )
        )
        self.max_problem_chars = max_problem_chars

    def search(
        self,
        query_code: str,
        *,
        top_k: int = 3,
        problem_id: str | None = None,
        problem_name: str | None = None,
        problem_description: str | None = None,
        source_lang: str = "Python",
        target_lang: str = "C++",
        same_problem_first: bool = True,
    ) -> List[Dict[str, Any]]:
        if not isinstance(query_code, str) or not query_code.strip():
            raise ValueError("query_code must be a non-empty string.")
        if top_k <= 0:
            raise ValueError("top_k must be positive.")

        query_text = build_retrieval_text(
            query_code,
            language=source_lang,
            problem_id=problem_id,
            problem_name=problem_name,
            problem_description=problem_description,
            max_problem_chars=self.max_problem_chars,
        )
        query_vector = self.embedder.embed_text(query_text).reshape(1, -1)

        candidate_k = min(max(top_k * 5, 20), len(self.metadata))
        scores, indices = self.index.search(query_vector, candidate_k)

        results: List[Dict[str, Any]] = []
        for score, idx in zip(scores[0], indices[0]):
            if idx == -1:
                continue

            item = dict(self.metadata[idx])
            if source_lang and item.get("source_lang") != source_lang:
                continue
            if target_lang and item.get("target_lang") != target_lang:
                continue

            item["score"] = float(score)
            item["same_problem"] = bool(problem_id and item.get("problem_id") == problem_id)
            results.append(item)

        if same_problem_first:
            results.sort(key=lambda item: (not item["same_problem"], -item["score"]))
        else:
            results.sort(key=lambda item: -item["score"])

        return results[:top_k]


def pretty_print(results: List[Dict[str, Any]]) -> None:
    if not results:
        print("No results found.")
        return

    for rank, item in enumerate(results, start=1):
        print("=" * 80)
        print(f"Rank: {rank}")
        print(f"ID: {item['id']}")
        print(f"Problem: {item.get('problem_id')} | {item.get('problem_name', '')}")
        print(f"Score: {item['score']:.4f}")
        print(f"Same problem: {item.get('same_problem', False)}")
        print("\n[Retrieved Python Source]")
        print(item["source_code"])
        print("\n[Retrieved Accepted C++ Reference]")
        print(item["target_code"])
        print()


def main() -> None:
    parser = argparse.ArgumentParser(description="Search a FAISS retrieval index for CodeNet references.")
    parser.add_argument("--index", required=True, help="Path to the FAISS index.")
    parser.add_argument("--meta", required=True, help="Path to the metadata JSON.")
    parser.add_argument("--query-file", default=None, help="Path to a Python source file to use as the query.")
    parser.add_argument("--query", default=None, help="Raw source code query string.")
    parser.add_argument("--problem-id", default=None, help="Optional CodeNet problem id.")
    parser.add_argument("--problem-name", default=None, help="Optional problem name.")
    parser.add_argument("--problem-description-file", default=None, help="Optional problem description text file.")
    parser.add_argument("--top-k", type=int, default=3, help="Number of nearest examples to retrieve.")
    parser.add_argument("--model-name", default="microsoft/codebert-base", help="Embedding model name.")
    args = parser.parse_args()

    if bool(args.query) == bool(args.query_file):
        raise ValueError("Provide exactly one of --query or --query-file.")

    if args.query_file:
        query_code = Path(args.query_file).read_text(encoding="utf-8")
    else:
        query_code = args.query

    problem_description = None
    if args.problem_description_file:
        problem_description = Path(args.problem_description_file).read_text(encoding="utf-8")

    searcher = CodeSearcher(
        index_path=args.index,
        metadata_path=args.meta,
        model_name=args.model_name,
    )
    results = searcher.search(
        query_code=query_code,
        top_k=args.top_k,
        problem_id=args.problem_id,
        problem_name=args.problem_name,
        problem_description=problem_description,
    )
    pretty_print(results)


if __name__ == "__main__":
    main()
