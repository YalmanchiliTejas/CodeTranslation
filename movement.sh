#!/bin/bash
# FILENAME: filter_problem_descriptions.sh

set -euo pipefail

cd /home/tyalaman/CodeTranslation

DATA_DIR="Project_CodeNet_Cleaned.nosync/data"
SRC_DESC_DIR="Project_CodeNet_Final.nosync/problem_descriptions"
DEST_DESC_DIR="Project_CodeNet_Cleaned.nosync/problem_descriptions"

if [ ! -d "$DATA_DIR" ]; then
  echo "ERROR: data folder not found: $DATA_DIR"
  exit 1
fi

if [ ! -d "$SRC_DESC_DIR" ]; then
  echo "ERROR: source problem_descriptions folder not found: $SRC_DESC_DIR"
  exit 1
fi

mkdir -p "$DEST_DESC_DIR"

echo "Clearing existing cleaned problem_descriptions folder..."
find "$DEST_DESC_DIR" -type f -name "*.html" -delete

echo "Copying only matching problem descriptions..."

matched=0
missing=0

for problem_path in "$DATA_DIR"/p*; do
  if [ ! -d "$problem_path" ]; then
    continue
  fi

  problem_id=$(basename "$problem_path")
  src_file="$SRC_DESC_DIR/${problem_id}.html"
  dest_file="$DEST_DESC_DIR/${problem_id}.html"

  if [ -f "$src_file" ]; then
    cp "$src_file" "$dest_file"
    matched=$((matched + 1))
  else
    echo "Missing description for: $problem_id"
    missing=$((missing + 1))
  fi
done

echo "Done."
echo "Matched descriptions copied: $matched"
echo "Missing descriptions: $missing"
echo "Destination: $DEST_DESC_DIR"

echo "Sample copied files:"
ls "$DEST_DESC_DIR" | head