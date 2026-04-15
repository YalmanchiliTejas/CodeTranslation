"""
Verification utilities for generated C++ code.

The verifier compiles the generated program and, when sample tests are available,
runs the executable against them. The results can be fed back into another repair
round.
"""

from __future__ import annotations

import subprocess
import tempfile
from dataclasses import dataclass, field
from pathlib import Path
from typing import List, Sequence


@dataclass
class SampleTest:
    input: str
    output: str


@dataclass
class TestCaseResult:
    input: str
    expected_output: str
    actual_output: str
    passed: bool
    stderr: str = ""
    timed_out: bool = False
    return_code: int | None = None


@dataclass
class VerificationResult:
    compile_success: bool
    compile_stdout: str = ""
    compile_stderr: str = ""
    binary_path: str | None = None
    test_results: List[TestCaseResult] = field(default_factory=list)

    @property
    def all_tests_passed(self) -> bool:
        return self.compile_success and all(test.passed for test in self.test_results)

    def failed_tests_as_dicts(self) -> List[dict]:
        failed = []
        for test in self.test_results:
            if not test.passed:
                failed.append(
                    {
                        "input": test.input,
                        "expected_output": test.expected_output,
                        "actual_output": test.actual_output,
                        "stderr": test.stderr,
                    }
                )
        return failed


def _normalize_output(text: str) -> str:
    lines = [line.rstrip() for line in text.replace("\r\n", "\n").replace("\r", "\n").split("\n")]
    while lines and lines[-1] == "":
        lines.pop()
    return "\n".join(lines)


class CppVerifier:
    def __init__(
        self,
        compiler: str = "g++",
        cpp_standard: str = "c++17",
        compile_timeout_sec: int = 20,
        run_timeout_sec: int = 5,
    ) -> None:
        self.compiler = compiler
        self.cpp_standard = cpp_standard
        self.compile_timeout_sec = compile_timeout_sec
        self.run_timeout_sec = run_timeout_sec

    def compile_code(self, code: str) -> VerificationResult:
        temp_dir = Path(tempfile.mkdtemp(prefix="codenet_translate_"))
        source_path = temp_dir / "main.cpp"
        binary_path = temp_dir / "main.out"
        source_path.write_text(code, encoding="utf-8")

        cmd = [
            self.compiler,
            str(source_path),
            "-std=" + self.cpp_standard,
            "-O2",
            "-pipe",
            "-o",
            str(binary_path),
        ]

        try:
            proc = subprocess.run(
                cmd,
                capture_output=True,
                text=True,
                timeout=self.compile_timeout_sec,
            )
        except subprocess.TimeoutExpired as exc:
            return VerificationResult(
                compile_success=False,
                compile_stdout=exc.stdout or "",
                compile_stderr=(exc.stderr or "") + "\nCompilation timed out.",
            )

        return VerificationResult(
            compile_success=(proc.returncode == 0),
            compile_stdout=proc.stdout,
            compile_stderr=proc.stderr,
            binary_path=str(binary_path) if proc.returncode == 0 else None,
        )

    def run_tests(
        self,
        binary_path: str | Path,
        sample_tests: Sequence[SampleTest | dict],
    ) -> List[TestCaseResult]:
        results: List[TestCaseResult] = []

        for raw_test in sample_tests:
            test = raw_test if isinstance(raw_test, SampleTest) else SampleTest(
                input=raw_test.get("input", ""),
                output=raw_test.get("output", ""),
            )

            try:
                proc = subprocess.run(
                    [str(binary_path)],
                    input=test.input,
                    capture_output=True,
                    text=True,
                    timeout=self.run_timeout_sec,
                )
                actual = proc.stdout
                passed = (
                    proc.returncode == 0 and
                    _normalize_output(actual) == _normalize_output(test.output)
                )
                results.append(
                    TestCaseResult(
                        input=test.input,
                        expected_output=test.output,
                        actual_output=actual,
                        passed=passed,
                        stderr=proc.stderr,
                        timed_out=False,
                        return_code=proc.returncode,
                    )
                )
            except subprocess.TimeoutExpired as exc:
                results.append(
                    TestCaseResult(
                        input=test.input,
                        expected_output=test.output,
                        actual_output=exc.stdout or "",
                        passed=False,
                        stderr=(exc.stderr or "") + "\nExecution timed out.",
                        timed_out=True,
                        return_code=None,
                    )
                )

        return results

    def verify(self, code: str, sample_tests: Sequence[SampleTest | dict] | None = None) -> VerificationResult:
        result = self.compile_code(code)
        if not result.compile_success or not sample_tests:
            return result

        result.test_results = self.run_tests(result.binary_path, sample_tests)
        return result
