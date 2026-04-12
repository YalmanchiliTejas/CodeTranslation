import os
import shutil
import random

# Use a fixed seed so your results are reproducible 
# (Important for your Purdue research paper!)
random.seed(42)

# Paths
SOURCE_BASE = "../../Project_CodeNet_Cleaned.nosync"
SUBSET_BASE = "../../Project_CodeNet_Final.nosync"

SOURCE_DATA = os.path.join(SOURCE_BASE, "data")
SOURCE_META = os.path.join(SOURCE_BASE, "metadata")

SUBSET_DATA = os.path.join(SUBSET_BASE, "data")
SUBSET_META = os.path.join(SUBSET_BASE, "metadata")

NUM_PROBLEMS = 150

def create_subset():
    if not os.path.exists(SOURCE_DATA):
        print(f"Error: Could not find {SOURCE_DATA}. Did you run the cleanup script first?")
        return

    # 1. Get list of all available problems
    all_problems = [p for p in os.listdir(SOURCE_DATA) if os.path.isdir(os.path.join(SOURCE_DATA, p))]
    
    subset_problems = random.sample(all_problems, NUM_PROBLEMS)
    
    # Create new structure
    os.makedirs(SUBSET_DATA, exist_ok=True)
    os.makedirs(SUBSET_META, exist_ok=True)

    print(f"Copying {len(subset_problems)} problems to {SUBSET_BASE}...")

    # 2. Copy the Data folders
    for prob_id in subset_problems:
        src_prob_path = os.path.join(SOURCE_DATA, prob_id)
        dst_prob_path = os.path.join(SUBSET_DATA, prob_id)
        shutil.copytree(src_prob_path, dst_prob_path)

    # 3. Copy the associated Metadata CSVs
    # In CodeNet, some CSVs cover multiple problems, so we find CSVs 
    # that contain our subset problem IDs.
    all_csvs = [f for f in os.listdir(SOURCE_META) if f.endswith('.csv')]
    
    for csv_file in all_csvs:
        src_csv_path = os.path.join(SOURCE_META, csv_file)
        import pandas as pd
        
        df = pd.read_csv(src_csv_path)
        # Only keep rows if the problem_id is in our random subset
        filtered_df = df[df['problem_id'].isin(subset_problems)]
        
        if not filtered_df.empty:
            dst_csv_path = os.path.join(SUBSET_META, csv_file)
            filtered_df.to_csv(dst_csv_path, index=False)

    print("\nSubset creation complete!")
    print(f"Location: {SUBSET_BASE}")

if __name__ == "__main__":
    create_subset()