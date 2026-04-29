"""
Search a FAISS CodeNet retrieval index for top-k similar accepted references.

This version supports problem-aware querying using:
- problem_id
- problem_name
- problem_description
- sample_tests
- Python source code
"""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path
from typing import Any, Dict, List

import faiss

from retrieval.embedder import CodeEmbedder, EmbedderConfig


STOPWORDS = {
    "the", "a", "an", "and", "or", "of", "to", "in", "is", "are",
    "for", "with", "given", "print", "input", "output", "integer",
    "integers", "value", "values", "number", "numbers", "line",
    "lines", "you", "your", "will", "can", "be", "as", "by",
}


def _clip(text: str | None, max_chars: int) -> str:
    text = (text or "").strip()

    if max_chars <= 0:
        return ""

    if len(text) <= max_chars:
        return text

    return text[:max_chars].rstrip() + "\n...[truncated]"


def tokenize_text(text: str) -> set[str]:
    tokens = re.findall(r"[A-Za-z_][A-Za-z_0-9]*|\d+", (text or "").lower())
    return {tok for tok in tokens if tok not in STOPWORDS and len(tok) > 1}


def jaccard(a: str, b: str) -> float:
    a_tokens = tokenize_text(a)
    b_tokens = tokenize_text(b)

    if not a_tokens or not b_tokens:
        return 0.0

    return len(a_tokens & b_tokens) / len(a_tokens | b_tokens)


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


def build_problem_aware_query_text(
    *,
    query_code: str,
    problem_id: str | None = None,
    problem_name: str | None = None,
    problem_description: str | None = None,
    sample_tests: Any = None,
    max_problem_chars: int = 600,
    max_code_chars: int = 1200,
) -> str:
    parts: List[str] = []

    if problem_id:
        parts.append(f"Problem ID:\n{problem_id}")

    if problem_name:
        parts.append(f"Problem Name:\n{problem_name}")

    description = _clip(problem_description, max_problem_chars)
    if description:
        parts.append(f"Problem Description:\n{description}")

    sample_text = format_sample_tests(sample_tests, max_tests=1, max_chars=500)
    if sample_text:
        parts.append(f"Sample Tests:\n{sample_text}")

    parts.append(f"Python Source Code:\n{_clip(query_code, max_code_chars)}")

    return "\n\n".join(parts).strip()


class CodeSearcher:
    def __init__(
        self,
        index_path: str | Path,
        metadata_path: str | Path,
        model_name: str = "microsoft/codebert-base",
        max_problem_chars: int = 600,
        max_code_chars: int = 1200,
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
        self.max_code_chars = max_code_chars

    def _rerank(
        self,
        *,
        query_problem_description: str | None,
        query_sample_tests: Any,
        candidates: List[Dict[str, Any]],
    ) -> List[Dict[str, Any]]:
        query_desc = query_problem_description or ""
        query_samples = format_sample_tests(query_sample_tests, max_tests=1, max_chars=500)

        reranked: List[Dict[str, Any]] = []

        for item in candidates:
            codebert_score = float(item.get("score", 0.0))
            desc_score = jaccard(query_desc, item.get("problem_description", ""))
            sample_score = jaccard(
                query_samples,
                format_sample_tests(item.get("sample_tests", []), max_tests=1, max_chars=500),
            )

            # CodeBERT still matters most, but problem/sample overlap prevents nonsense retrieval.
            rerank_score = (
                0.65 * codebert_score
                + 0.25 * desc_score
                + 0.10 * sample_score
            )

            new_item = dict(item)
            new_item["rerank_score"] = float(rerank_score)
            new_item["desc_overlap_score"] = float(desc_score)
            new_item["sample_overlap_score"] = float(sample_score)
            reranked.append(new_item)

        reranked.sort(key=lambda x: x["rerank_score"], reverse=True)
        return reranked

    def search(
        self,
        query_code: str,
        *,
        top_k: int = 3,
        problem_id: str | None = None,
        problem_name: str | None = None,
        problem_description: str | None = None,
        sample_tests: Any = None,
        source_lang: str = "Python",
        target_lang: str = "C++",
        same_problem_first: bool = False,
    ) -> List[Dict[str, Any]]:
        if not isinstance(query_code, str) or not query_code.strip():
            raise ValueError("query_code must be a non-empty string.")

        if top_k <= 0:
            return []

        query_text = build_problem_aware_query_text(
            query_code=query_code,
            problem_id=problem_id,
            problem_name=problem_name,
            problem_description=problem_description,
            sample_tests=sample_tests,
            max_problem_chars=self.max_problem_chars,
            max_code_chars=self.max_code_chars,
        )

        query_vector = self.embedder.embed_text(query_text).reshape(1, -1)

        # Retrieve more than needed, then rerank.
        candidate_k = min(max(top_k * 10, 50), len(self.metadata))
        scores, indices = self.index.search(query_vector, candidate_k)

        candidates: List[Dict[str, Any]] = []

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
            candidates.append(item)

        if same_problem_first:
            candidates.sort(key=lambda item: (not item["same_problem"], -item["score"]))
            return candidates[:top_k]

        reranked = self._rerank(
            query_problem_description=problem_description,
            query_sample_tests=sample_tests,
            candidates=candidates,
        )

        return reranked[:top_k]


def pretty_print(results: List[Dict[str, Any]]) -> None:
    if not results:
        print("No results found.")
        return

    for rank, item in enumerate(results, start=1):
        print("=" * 80)
        print(f"Rank: {rank}")
        print(f"ID: {item['id']}")
        print(f"Problem: {item.get('problem_id')} | {item.get('problem_name', '')}")
        print(f"CodeBERT Score: {item.get('score', 0.0):.4f}")
        print(f"Rerank Score: {item.get('rerank_score', 0.0):.4f}")
        print(f"Desc overlap: {item.get('desc_overlap_score', 0.0):.4f}")
        print(f"Sample overlap: {item.get('sample_overlap_score', 0.0):.4f}")
        print(f"Same problem: {item.get('same_problem', False)}")
        print("\n[Retrieved Python Source]")
        print(item["source_code"][:2000])
        print("\n[Retrieved Accepted C++ Reference]")
        print(item["target_code"][:2000])
        print()


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Search a problem-aware FAISS retrieval index for CodeNet references."
    )

    parser.add_argument("--index", required=True, help="Path to the FAISS index.")
    parser.add_argument("--meta", required=True, help="Path to the metadata JSON.")
    parser.add_argument("--query-file", default=None, help="Path to a Python source file to use as the query.")
    parser.add_argument("--query", default=None, help="Raw source code query string.")
    parser.add_argument("--problem-id", default=None, help="Optional CodeNet problem id.")
    parser.add_argument("--problem-name", default=None, help="Optional problem name.")
    parser.add_argument("--problem-description-file", default=None, help="Optional problem description text file.")
    parser.add_argument("--sample-tests-file", default=None, help="Optional sample tests JSON file.")
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

    sample_tests = []
    if args.sample_tests_file:
        with Path(args.sample_tests_file).open("r", encoding="utf-8") as f:
            sample_tests = json.load(f)

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
        sample_tests=sample_tests,
    )

    pretty_print(results)


if __name__ == "__main__":
    main()