import os
import pandas as pd
import shutil

# -----------------------------
# Paths
# -----------------------------
BASE_PATH = "/home/tyalaman/CodeTranslation/Project_CodeNet_Final.nosync"

ORIGINAL_DATA = os.path.join(BASE_PATH, "data")
ORIGINAL_META = os.path.join(BASE_PATH, "metadata")
ORIGINAL_DESCRIPTIONS = os.path.join(BASE_PATH, "problem_descriptions")

CLEAN_BASE = "/home/tyalaman/CodeTranslation/Project_CodeNet_Cleaned.nosync"
CLEAN_DATA = os.path.join(CLEAN_BASE, "data")
CLEAN_META = os.path.join(CLEAN_BASE, "metadata")
CLEAN_DESCRIPTIONS = os.path.join(CLEAN_BASE, "problem_descriptions")

KEEP_LANGS = {"Python", "C++"}
KEEP_STATUS = "Accepted"


def safe_cleanup():
    os.makedirs(CLEAN_DATA, exist_ok=True)
    os.makedirs(CLEAN_META, exist_ok=True)
    os.makedirs(CLEAN_DESCRIPTIONS, exist_ok=True)

    if not os.path.exists(ORIGINAL_DATA):
        print(f"Original data path not found: {ORIGINAL_DATA}")
        return

    if not os.path.exists(ORIGINAL_META):
        print(f"Original metadata path not found: {ORIGINAL_META}")
        return

    csv_files = [f for f in os.listdir(ORIGINAL_META) if f.endswith(".csv")]

    for csv_file in csv_files:
        csv_path = os.path.join(ORIGINAL_META, csv_file)
        print(f"Processing metadata: {csv_file}...")

        try:
            df = pd.read_csv(csv_path)

            # problem_list.csv is problem-level metadata.
            # It does not have language/status columns, but build_codenet_pairs.py needs it.
            if csv_file == "problem_list.csv":
                df.to_csv(os.path.join(CLEAN_META, csv_file), index=False)
                print("Copied problem_list.csv")
                continue

            # Skip metadata files that are not submission-level metadata.
            if "language" not in df.columns or "status" not in df.columns:
                print(f"Skipping non-submission metadata file: {csv_file}")
                continue

            filtered_df = df[
                (df["language"].isin(KEEP_LANGS)) &
                (df["status"] == KEEP_STATUS)
            ]

            if filtered_df.empty:
                continue

            # Save filtered submission metadata.
            filtered_meta_path = os.path.join(CLEAN_META, csv_file)
            filtered_df.to_csv(filtered_meta_path, index=False)

            # Copy matching source files.
            for _, row in filtered_df.iterrows():
                sub_id = str(row["submission_id"])
                prob_id = str(row["problem_id"])
                lang = str(row["language"])
                ext = str(row["filename_ext"]).lstrip(".")

                src_file = f"{sub_id}.{ext}"
                src_path = os.path.join(ORIGINAL_DATA, prob_id, lang, src_file)

                dst_dir = os.path.join(CLEAN_DATA, prob_id, lang)
                os.makedirs(dst_dir, exist_ok=True)

                dst_path = os.path.join(dst_dir, src_file)

                if os.path.exists(src_path):
                    shutil.copy2(src_path, dst_path)
                else:
                    print(f"Warning: source file not found: {src_path}")

        except Exception as e:
            print(f"Error processing {csv_file}: {e}")

    # Copy problem descriptions because build_codenet_pairs.py uses them
    # for problem_description and sample_tests.
    if os.path.exists(ORIGINAL_DESCRIPTIONS):
        print("Copying problem descriptions...")

        for filename in os.listdir(ORIGINAL_DESCRIPTIONS):
            if not filename.endswith(".html"):
                continue

            src = os.path.join(ORIGINAL_DESCRIPTIONS, filename)
            dst = os.path.join(CLEAN_DESCRIPTIONS, filename)

            if os.path.exists(src):
                shutil.copy2(src, dst)

        print(f"Copied problem descriptions to: {CLEAN_DESCRIPTIONS}")
    else:
        print(f"Warning: original problem_descriptions folder not found: {ORIGINAL_DESCRIPTIONS}")

    print(f"\nSuccess! Cleaned data is now in: {CLEAN_BASE}")


if __name__ == "__main__":
    safe_cleanup()