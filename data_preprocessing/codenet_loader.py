"""
Utilities for loading Project CodeNet metadata and source files.

The loader follows CodeNet's documented structure:

Project_CodeNet/
    data/<problem_id>/<language>/<submission_id>.<ext>
    metadata/problem_list.csv
    metadata/<problem_id>.csv
    problem_descriptions/<problem_id>.html
"""

from __future__ import annotations

import csv
import html
import re
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, Iterable, Iterator, List


@dataclass
class ProblemInfo:
    problem_id: str
    name: str = ""
    dataset: str = ""
    time_limit_ms: int | None = None
    memory_limit_kb: int | None = None
    rating: int | None = None
    tags: List[str] | None = None
    complexity: str | None = None


@dataclass
class SubmissionRecord:
    submission_id: str
    problem_id: str
    user_id: str
    date: int | None
    language: str
    original_language: str
    filename_ext: str
    status: str
    cpu_time: int | None
    memory: int | None
    code_size: int | None
    accuracy: str | None
    source_path: str
    source_code: str | None = None


def _safe_int(value: str | None) -> int | None:
    if value is None:
        return None
    value = str(value).strip()
    if not value:
        return None
    try:
        return int(value)
    except ValueError:
        return None


def strip_html_to_text(raw_html: str) -> str:
    text = re.sub(r"(?is)<(script|style).*?>.*?</\1>", " ", raw_html)
    text = re.sub(r"(?i)<br\s*/?>", "\n", text)
    text = re.sub(r"(?i)</p>", "\n\n", text)
    text = re.sub(r"(?i)</div>", "\n", text)
    text = re.sub(r"(?i)</li>", "\n", text)
    text = re.sub(r"(?s)<[^>]+>", " ", text)
    text = html.unescape(text)
    text = re.sub(r"[ \t]+\n", "\n", text)
    text = re.sub(r"\n{3,}", "\n\n", text)
    return text.strip()


def _clean_pre_text(block: str) -> str:
    text = re.sub(r"(?s)<[^>]+>", "", block)
    text = html.unescape(text)
    text = text.replace("\r\n", "\n").replace("\r", "\n")
    return text.strip("\n")


def extract_sample_tests_from_html(raw_html: str) -> List[dict]:
    """
    Best-effort extraction of sample input/output blocks from a problem html page.
    """
    html_text = raw_html.replace("\r\n", "\n").replace("\r", "\n")
    pre_blocks = list(re.finditer(r"(?is)<pre[^>]*>(.*?)</pre>", html_text))
    if not pre_blocks:
        return []

    label_pattern = re.compile(
        r"(?is)(sample\s*(input|output)(?:\s*\d+)?)|"
        r"(input\s*example(?:\s*\d+)?)|"
        r"(output\s*example(?:\s*\d+)?)"
    )

    labeled_blocks: List[tuple[str, str]] = []
    for match in pre_blocks:
        start = max(0, match.start() - 300)
        context = html_text[start:match.start()]
        labels = list(label_pattern.finditer(context))
        if not labels:
            continue
        label = labels[-1].group(0).lower()
        labeled_blocks.append((label, _clean_pre_text(match.group(1))))

    inputs: List[str] = []
    outputs: List[str] = []

    for label, block in labeled_blocks:
        if "input" in label:
            inputs.append(block)
        elif "output" in label:
            outputs.append(block)

    pair_count = min(len(inputs), len(outputs))
    if pair_count == 0:
        return []

    return [{"input": inputs[i], "output": outputs[i]} for i in range(pair_count)]


def load_problem_catalog(codenet_root: str | Path) -> Dict[str, ProblemInfo]:
    root = Path(codenet_root)
    csv_path = root / "metadata" / "problem_list.csv"
    if not csv_path.exists():
        raise FileNotFoundError(f"problem_list.csv not found at: {csv_path}")

    catalog: Dict[str, ProblemInfo] = {}
    with csv_path.open("r", encoding="utf-8", newline="") as f:
        reader = csv.DictReader(f)
        for row in reader:
            problem_id = row["id"]
            tags = [tag for tag in (row.get("tags") or "").split("|") if tag]
            catalog[problem_id] = ProblemInfo(
                problem_id=problem_id,
                name=row.get("name", ""),
                dataset=row.get("dataset", ""),
                time_limit_ms=_safe_int(row.get("time_limit")),
                memory_limit_kb=_safe_int(row.get("memory_limit")),
                rating=_safe_int(row.get("rating")),
                tags=tags,
                complexity=row.get("complexity") or None,
            )
    return catalog


def get_problem_description_html(codenet_root: str | Path, problem_id: str) -> str:
    path = Path(codenet_root) / "problem_descriptions" / f"{problem_id}.html"
    if not path.exists():
        return ""
    return path.read_text(encoding="utf-8", errors="ignore")


def get_problem_description_text(codenet_root: str | Path, problem_id: str) -> str:
    raw_html = get_problem_description_html(codenet_root, problem_id)
    if not raw_html:
        return ""
    return strip_html_to_text(raw_html)


def get_problem_sample_tests(codenet_root: str | Path, problem_id: str) -> List[dict]:
    raw_html = get_problem_description_html(codenet_root, problem_id)
    if not raw_html:
        return []
    return extract_sample_tests_from_html(raw_html)


def build_source_path(
    codenet_root: str | Path,
    problem_id: str,
    language: str,
    submission_id: str,
    filename_ext: str,
) -> Path:
    ext = filename_ext.lstrip(".")
    return Path(codenet_root) / "data" / problem_id / language / f"{submission_id}.{ext}"


def iter_problem_submissions(
    codenet_root: str | Path,
    problem_id: str,
    *,
    languages: Iterable[str] | None = None,
    accepted_only: bool = False,
    load_code: bool = False,
    max_code_size: int | None = None,
) -> Iterator[SubmissionRecord]:
    root = Path(codenet_root)
    csv_path = root / "metadata" / f"{problem_id}.csv"
    if not csv_path.exists():
        return

    language_filter = {lang for lang in languages} if languages else None

    with csv_path.open("r", encoding="utf-8", newline="") as f:
        reader = csv.DictReader(f)
        for row in reader:
            language = row.get("language", "")
            status = row.get("status", "")

            if language_filter and language not in language_filter:
                continue
            if accepted_only and status != "Accepted":
                continue

            code_size = _safe_int(row.get("code_size"))
            if max_code_size is not None and code_size is not None and code_size > max_code_size:
                continue

            path = build_source_path(
                codenet_root=root,
                problem_id=problem_id,
                language=language,
                submission_id=row["submission_id"],
                filename_ext=row.get("filename_ext", ""),
            )

            source_code = None
            if load_code and path.exists():
                source_code = path.read_text(encoding="utf-8", errors="ignore")

            yield SubmissionRecord(
                submission_id=row["submission_id"],
                problem_id=row["problem_id"],
                user_id=row.get("user_id", ""),
                date=_safe_int(row.get("date")),
                language=language,
                original_language=row.get("original_language", ""),
                filename_ext=row.get("filename_ext", ""),
                status=status,
                cpu_time=_safe_int(row.get("cpu_time")),
                memory=_safe_int(row.get("memory")),
                code_size=code_size,
                accuracy=row.get("accuracy") or None,
                source_path=str(path),
                source_code=source_code,
            )


def load_submission_code(record: SubmissionRecord) -> str:
    if record.source_code is not None:
        return record.source_code
    path = Path(record.source_path)
    if not path.exists():
        raise FileNotFoundError(f"Submission source file not found: {path}")
    return path.read_text(encoding="utf-8", errors="ignore")
