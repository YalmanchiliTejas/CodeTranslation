"""
Prompt builder for retrieval-augmented Python -> C++ translation using Project CodeNet.

This module takes:
- the input Python source code
- retrieved accepted C++ references from the same or similar CodeNet tasks
- translation constraints
- optional verification feedback from a previous repair round

and constructs a prompt for the generative model.
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
            "Generate a complete standalone competitive-programming style program unless the source is clearly just a function snippet.",
            "Use fast, idiomatic C++ that matches accepted Project CodeNet style.",
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


def format_reference(example: Dict[str, Any], idx: int) -> str:
    problem_id = example.get("problem_id", "")
    example_id = example.get("id", f"reference_{idx}")
    score = example.get("score")
    source_code = example.get("source_code", "").strip()
    target_code = example.get("target_code", "").strip()
    same_problem = example.get("same_problem", False)

    header = f"Reference {idx} (ID: {example_id}"
    if problem_id:
        header += f", problem_id={problem_id}"
    if score is not None:
        header += f", score={score:.4f}"
    if same_problem:
        header += ", same_problem=True"
    header += ")"

    return f"""{header}
Python source from dataset:
{source_code}

Accepted C++ reference:
{target_code}
"""


def _format_problem_context(problem_context: ProblemContext | None) -> str:
    if problem_context is None:
        return "No explicit problem context provided."

    parts: List[str] = []
    if problem_context.problem_id:
        parts.append(f"Problem ID: {problem_context.problem_id}")
    if problem_context.problem_name:
        parts.append(f"Problem Name: {problem_context.problem_name}")
    if problem_context.problem_description:
        parts.append("Problem Description:")
        parts.append(problem_context.problem_description.strip())

    if problem_context.sample_tests:
        parts.append("Sample Tests:")
        for idx, test in enumerate(problem_context.sample_tests, start=1):
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
) -> str:
    if not isinstance(source_code, str) or not source_code.strip():
        raise ValueError("source_code must be a non-empty string.")

    constraints = constraints or TranslationConstraints()
    rules = "\n".join(f"- {rule}" for rule in constraints.to_bullets())

    if retrieved_examples:
        formatted_examples = "\n\n".join(
            format_reference(example, idx + 1)
            for idx, example in enumerate(retrieved_examples)
        )
    else:
        formatted_examples = "No accepted C++ references were retrieved."

    repair_section = ""
    if previous_attempt is not None or verification_feedback is not None:
        parts: List[str] = [
            "You are repairing a previous C++ attempt that failed verification."
        ]
        if previous_attempt:
            parts.append("Previous attempt:")
            parts.append(previous_attempt.strip())
        if verification_feedback:
            feedback_text = verification_feedback.to_text()
            if feedback_text:
                parts.append("Verification feedback:")
                parts.append(feedback_text)
        repair_section = "\n\n".join(parts).strip()

    prompt = f"""You are an expert competitive-programming code translator.

Requirements:
{rules}

Problem Context:
{_format_problem_context(problem_context)}

Accepted Reference Solutions:
{formatted_examples}

Source Python Code:
{source_code.strip()}
"""

    if repair_section:
        prompt += f"\n\nRepair Context:\n{repair_section}\n"

    prompt += "\nTarget C++ Code:\n"
    return prompt
