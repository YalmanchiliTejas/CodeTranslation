"""
CodeBERT-based embedder for source-code retrieval.

Usage:
    from embedder import CodeEmbedder

    embedder = CodeEmbedder()
    vec = embedder.embed_text("def add(a, b): return a + b")
"""

from __future__ import annotations

from dataclasses import dataclass
from typing import List, Sequence

import numpy as np
import torch
from transformers import AutoModel, AutoTokenizer


@dataclass
class EmbedderConfig:
    model_name: str = "microsoft/codebert-base"
    max_length: int = 256
    pooling: str = "cls"   # supported: "cls", "mean"
    normalize: bool = True


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
        """
        Pool token embeddings into a single vector.

        Args:
            hidden_state: [batch, seq_len, hidden_dim]
            attention_mask: [batch, seq_len]

        Returns:
            [batch, hidden_dim]
        """
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
        """
        Embed a batch of code/text snippets.

        Returns:
            np.ndarray of shape [len(texts), hidden_dim], dtype=float32
        """
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
        """
        Embed a single code/text snippet.

        Returns:
            np.ndarray of shape [hidden_dim], dtype=float32
        """
        if not isinstance(text, str) or not text.strip():
            raise ValueError("embed_text expects a non-empty string.")

        return self.embed_batch([text], batch_size=1)[0]
