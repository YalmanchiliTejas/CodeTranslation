"""
Prompt builder for retrieval-augmented code translation.

This module takes:
- the input source code
- retrieved source/target examples from the retriever
- translation constraints

and constructs a clean prompt for a generative model.
"""

from __future__ import annotations

from dataclasses import dataclass, field
from typing import Any, Dict, List, Sequence


@dataclass
class TranslationConstraints:
    source_language: str = "Python"
    target_language: str = "C++"
    target_standard: str = "C++17"
    preserve_function_name: bool = True
    use_stl: bool = True
    avoid_raw_pointers: bool = True
    prefer_const_references: bool = True
    output_code_only: bool = True
    extra_rules: List[str] = field(default_factory=list)

    def to_bullets(self) -> List[str]:
        bullets = [
            f"Translate from {self.source_language} to {self.target_language}.",
            f"Target standard: {self.target_standard}.",
        ]

        if self.preserve_function_name:
            bullets.append("Preserve the original function name when reasonable.")
        if self.use_stl:
            bullets.append("Prefer STL containers and algorithms where appropriate.")
        if self.avoid_raw_pointers:
            bullets.append("Avoid raw pointers unless absolutely necessary.")
        if self.prefer_const_references:
            bullets.append("Use const references for large inputs when appropriate.")
        if self.output_code_only:
            bullets.append("Return only compilable target code. Do not include explanations.")

        bullets.extend(self.extra_rules)
        return bullets


def format_example(example: Dict[str, Any], idx: int) -> str:
    source_code = example.get("source_code", "").strip()
    target_code = example.get("target_code", "").strip()
    example_id = example.get("id", f"example_{idx}")
    score = example.get("score", None)

    header = f"Example {idx} (ID: {example_id}"
    if score is not None:
        header += f", score={score:.4f}"
    header += ")"

    return f"""{header}
Source:
{source_code}

Target:
{target_code}
"""


def build_translation_prompt(
    source_code: str,
    retrieved_examples: Sequence[Dict[str, Any]],
    constraints: TranslationConstraints | None = None,
) -> str:
    """
    Build a prompt for retrieval-augmented code translation.

    Args:
        source_code: Input source-language code
        retrieved_examples: Top-k retrieved examples from the retriever
        constraints: Translation settings/rules

    Returns:
        A formatted prompt string
    """
    if not isinstance(source_code, str) or not source_code.strip():
        raise ValueError("source_code must be a non-empty string.")

    constraints = constraints or TranslationConstraints()
    rules = "\n".join(f"- {rule}" for rule in constraints.to_bullets())

    if retrieved_examples:
        formatted_examples = "\n\n".join(
            format_example(example, idx + 1)
            for idx, example in enumerate(retrieved_examples)
        )
    else:
        formatted_examples = "No retrieved examples were provided."

    prompt = f"""You are an expert code translator.

Requirements:
{rules}

Retrieved Examples:
{formatted_examples}

Now translate the following source code.

Source Code:
{source_code}

Target Code:
"""
    return prompt


if __name__ == "__main__":
    demo_source = "def add(a, b): return a + b"
    demo_examples = [
        {
            "id": "ex_001",
            "source_code": "def square(x): return x * x",
            "target_code": "int square(int x) { return x * x; }",
            "score": 0.91,
        }
    ]

    prompt = build_translation_prompt(demo_source, demo_examples)
    print(prompt)
