"""
Prompt builder for retrieval-augmented Python -> C++ translation using Project CodeNet.

Supports:
- problem context
- retrieved Python/C++ references
- translation constraints
- verification feedback for repair rounds
"""

from __future__ import annotations

from dataclasses import dataclass, field
from typing import Any, Dict, List, Sequence


@dataclass
class ProblemContext:
    problem_id: str = ""
    problem_name: str = ""
    problem_description: str = ""
    sample_tests: List[Dict[str, str]] = field(default_factory=list)


@dataclass
class VerificationFeedback:
    compile_success: bool = False
    compile_stderr: str = ""
    failed_tests: List[Dict[str, str]] = field(default_factory=list)

    def to_text(self) -> str:
        parts: List[str] = []

        if self.compile_stderr.strip():
            parts.append("Compiler output:")
            parts.append(self.compile_stderr.strip())

        if self.failed_tests:
            parts.append("Failed sample tests:")

            for idx, test in enumerate(self.failed_tests, start=1):
                parts.append(f"Test {idx} input:\n{test.get('input', '').strip()}")
                parts.append(f"Expected output:\n{test.get('expected_output', '').strip()}")
                parts.append(f"Actual output:\n{test.get('actual_output', '').strip()}")

        return "\n\n".join(parts).strip()


@dataclass
class TranslationConstraints:
    source_language: str = "Python"
    target_language: str = "C++"
    target_standard: str = "C++17"
    preserve_function_name: bool = False
    use_stl: bool = True
    avoid_raw_pointers: bool = True
    prefer_const_references: bool = True
    output_code_only: bool = True
    extra_rules: List[str] = field(default_factory=list)

    def to_bullets(self) -> List[str]:
        bullets = [
            f"Translate from {self.source_language} to {self.target_language}.",
            f"Target standard: {self.target_standard}.",
            "Translate the given Python source code directly. The Python source is the authority.",
            "Preserve the exact input/output behavior of the Python source.",
            "Retrieved examples are references only. Do not copy their algorithm unless it matches the Python source.",
            "Generate a complete standalone C++17 program with necessary includes and main().",
            "Use fast, idiomatic competitive-programming C++.",
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
            bullets.append("Return only compilable C++ code. Do not include explanations, markdown fences, or compiler-output text.")

        bullets.extend(self.extra_rules)
        return bullets


def _clip(text: str, max_chars: int) -> str:
    text = (text or "").strip()

    if max_chars <= 0:
        return ""

    if len(text) <= max_chars:
        return text

    return text[:max_chars].rstrip() + "\n...[truncated]"


def format_reference(
    example: Dict[str, Any],
    idx: int,
    max_code_chars: int = 500,
) -> str:
    problem_id = example.get("problem_id", "")
    problem_name = example.get("problem_name", "")
    example_id = example.get("id", f"reference_{idx}")
    score = example.get("score")
    rerank_score = example.get("rerank_score")
    source_code = _clip(example.get("source_code", ""), max_code_chars)
    target_code = _clip(example.get("target_code", ""), max_code_chars)
    same_problem = example.get("same_problem", False)

    header = f"Reference {idx} (ID: {example_id}"

    if problem_id:
        header += f", problem_id={problem_id}"

    if problem_name:
        header += f", problem_name={problem_name}"

    if score is not None:
        header += f", codebert_score={score:.4f}"

    if rerank_score is not None:
        header += f", rerank_score={rerank_score:.4f}"

    if same_problem:
        header += ", same_problem=True"

    header += ")"

    return f"""{header}
This is only a reference. Do not copy it unless the algorithm matches the Python source.

Reference Python excerpt:
{source_code}

Reference C++ excerpt:
{target_code}
"""


def format_problem_context(
    problem_context: ProblemContext | None,
    *,
    max_problem_chars: int = 300,
    max_sample_tests: int = 1,
) -> str:
    if problem_context is None:
        return "No explicit problem context provided."

    parts: List[str] = []

    if problem_context.problem_id:
        parts.append(f"Problem ID: {problem_context.problem_id}")

    if problem_context.problem_name:
        parts.append(f"Problem Name: {problem_context.problem_name}")

    if problem_context.problem_description:
        desc = _clip(problem_context.problem_description, max_problem_chars)
        if desc:
            parts.append("Problem Description:")
            parts.append(desc)

    if problem_context.sample_tests:
        parts.append("Sample Tests:")

        for idx, test in enumerate(problem_context.sample_tests[:max_sample_tests], start=1):
            parts.append(f"Sample Input {idx}:\n{test.get('input', '').strip()}")
            parts.append(f"Sample Output {idx}:\n{test.get('output', '').strip()}")

    return "\n\n".join(parts).strip() if parts else "No explicit problem context provided."


def build_translation_prompt(
    source_code: str,
    retrieved_examples: Sequence[Dict[str, Any]],
    constraints: TranslationConstraints | None = None,
    problem_context: ProblemContext | None = None,
    previous_attempt: str | None = None,
    verification_feedback: VerificationFeedback | None = None,
    max_problem_chars: int = 300,
    max_sample_tests: int = 1,
    max_reference_code_chars: int = 500,
) -> str:
    if not isinstance(source_code, str) or not source_code.strip():
        raise ValueError("source_code must be a non-empty string.")

    constraints = constraints or TranslationConstraints()
    rules = "\n".join(f"- {rule}" for rule in constraints.to_bullets())

    if retrieved_examples:
        formatted_examples = "\n\n".join(
            format_reference(
                example,
                idx + 1,
                max_code_chars=max_reference_code_chars,
            )
            for idx, example in enumerate(retrieved_examples)
        )
    else:
        formatted_examples = "No accepted C++ references were retrieved."

    problem_text = format_problem_context(
        problem_context,
        max_problem_chars=max_problem_chars,
        max_sample_tests=max_sample_tests,
    )

    repair_section = ""

    if previous_attempt is not None or verification_feedback is not None:
        repair_parts: List[str] = [
            "Repair Mode:",
            "The previous C++ attempt failed verification. Produce a corrected complete C++17 program.",
            "Do not repeat compiler error logs. Return only corrected C++ source code.",
        ]

        if previous_attempt:
            repair_parts.append("Previous C++ attempt:")
            repair_parts.append(_clip(previous_attempt.strip(), 1200))

        if verification_feedback:
            feedback_text = verification_feedback.to_text()
            if feedback_text:
                repair_parts.append("Verification feedback:")
                repair_parts.append(_clip(feedback_text, 1200))

        repair_section = "\n\n".join(repair_parts).strip()

    prompt_parts = [
        "You are an expert Python-to-C++ competitive-programming translator.",
        "",
        "Requirements:",
        rules,
        "",
        "Problem Context:",
        problem_text,
        "",
        "Retrieved References:",
        formatted_examples,
    ]

    if repair_section:
        prompt_parts.extend(["", repair_section])

    prompt_parts.extend(
        [
            "",
            "Now translate the Python source code below into C++17.",
            "Use the Python source code as the ground truth.",
            "",
            "Python Source Code:",
            source_code.strip(),
            "",
            "C++17 Code:",
        ]
    )

    return "\n".join(prompt_parts)


if __name__ == "__main__":
    demo_context = ProblemContext(
        problem_id="p_demo",
        problem_name="Addition",
        problem_description="Given two integers, print their sum.",
        sample_tests=[{"input": "2 3\n", "output": "5\n"}],
    )

    demo_prompt = build_translation_prompt(
        source_code="a, b = map(int, input().split())\nprint(a + b)",
        retrieved_examples=[],
        constraints=TranslationConstraints(),
        problem_context=demo_context,
    )

    print(demo_prompt)