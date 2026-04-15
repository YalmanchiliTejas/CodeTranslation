"""
CodeBERT-based embedder for CodeNet-aware code retrieval.

This version embeds code together with optional problem context so retrieval
can leverage both the source program and the underlying programming task.
"""

from __future__ import annotations

from dataclasses import dataclass
from typing import Any, Mapping, Sequence, List

import numpy as np
import torch
from transformers import AutoModel, AutoTokenizer


@dataclass
class EmbedderConfig:
    model_name: str = "microsoft/codebert-base"
    max_length: int = 512
    pooling: str = "cls"   # supported: "cls", "mean"
    normalize: bool = True
    problem_text_chars: int = 1600


def build_retrieval_text(
    code: str,
    *,
    language: str | None = None,
    problem_id: str | None = None,
    problem_name: str | None = None,
    problem_description: str | None = None,
    extra_tags: Sequence[str] | None = None,
    max_problem_chars: int = 1600,
) -> str:
    """
    Build a retrieval string that includes CodeNet task context.

    The goal is not to create a prompt, but a stable text representation
    whose embedding better reflects both program semantics and the
    underlying problem being solved.
    """
    if not isinstance(code, str) or not code.strip():
        raise ValueError("code must be a non-empty string.")

    parts: List[str] = []

    if language:
        parts.append(f"[LANG={language}]")
    if problem_id:
        parts.append(f"[PROBLEM_ID={problem_id}]")
    if problem_name:
        parts.append(f"[PROBLEM_NAME={problem_name}]")
    if extra_tags:
        parts.append(f"[TAGS={' | '.join(str(tag) for tag in extra_tags if str(tag).strip())}]")
    if problem_description:
        clipped = problem_description.strip()
        if max_problem_chars > 0:
            clipped = clipped[:max_problem_chars]
        parts.append("[PROBLEM_DESCRIPTION]")
        parts.append(clipped)

    parts.append("[CODE]")
    parts.append(code.strip())
    return "\n".join(parts)


class CodeEmbedder:
    """
    Wraps a Hugging Face model for embedding code snippets.

    Default behavior:
    - Uses CodeBERT
    - Uses the CLS token embedding
    - L2-normalizes vectors so cosine similarity can be used with FAISS
    """

    def __init__(
        self,
        config: EmbedderConfig | None = None,
        device: str | None = None,
    ) -> None:
        self.config = config or EmbedderConfig()

        if device is None:
            device = "cuda" if torch.cuda.is_available() else "cpu"

        self.device = torch.device(device)
        self.tokenizer = AutoTokenizer.from_pretrained(self.config.model_name)
        self.model = AutoModel.from_pretrained(self.config.model_name)
        self.model.to(self.device)
        self.model.eval()

    def _pool(self, hidden_state: torch.Tensor, attention_mask: torch.Tensor) -> torch.Tensor:
        if self.config.pooling == "cls":
            return hidden_state[:, 0, :]

        if self.config.pooling == "mean":
            mask = attention_mask.unsqueeze(-1).expand(hidden_state.size()).float()
            masked = hidden_state * mask
            summed = masked.sum(dim=1)
            counts = mask.sum(dim=1).clamp(min=1e-9)
            return summed / counts

        raise ValueError(f"Unsupported pooling strategy: {self.config.pooling}")

    def embed_batch(self, texts: Sequence[str], batch_size: int = 16) -> np.ndarray:
        if not texts:
            raise ValueError("embed_batch received an empty sequence.")

        all_vectors: List[np.ndarray] = []

        with torch.no_grad():
            for start in range(0, len(texts), batch_size):
                batch = list(texts[start : start + batch_size])

                inputs = self.tokenizer(
                    batch,
                    return_tensors="pt",
                    padding=True,
                    truncation=True,
                    max_length=self.config.max_length,
                )
                inputs = {k: v.to(self.device) for k, v in inputs.items()}

                outputs = self.model(**inputs)
                pooled = self._pool(outputs.last_hidden_state, inputs["attention_mask"])

                if self.config.normalize:
                    pooled = torch.nn.functional.normalize(pooled, p=2, dim=1)

                all_vectors.append(pooled.cpu().numpy().astype(np.float32))

        return np.vstack(all_vectors)

    def embed_text(self, text: str) -> np.ndarray:
        if not isinstance(text, str) or not text.strip():
            raise ValueError("embed_text expects a non-empty string.")
        return self.embed_batch([text], batch_size=1)[0]

    def embed_record(self, record: Mapping[str, Any]) -> np.ndarray:
        source_code = record.get("source_code", "")
        retrieval_text = build_retrieval_text(
            source_code,
            language=record.get("source_lang") or record.get("language"),
            problem_id=record.get("problem_id"),
            problem_name=record.get("problem_name"),
            problem_description=record.get("problem_description"),
            extra_tags=record.get("tags", []),
            max_problem_chars=self.config.problem_text_chars,
        )
        return self.embed_text(retrieval_text)
