import os
import pandas as pd
import shutil

# Paths based on your setup
BASE_PATH = "../../Project_CodeNet_Data.nosync"
ORIGINAL_DATA = os.path.join(BASE_PATH, "data")
ORIGINAL_META = os.path.join(BASE_PATH, "metadata")

# New "Safe" destinations
CLEAN_BASE = "../../Project_CodeNet_Cleaned.nosync"
CLEAN_DATA = os.path.join(CLEAN_BASE, "data")
CLEAN_META = os.path.join(CLEAN_BASE, "metadata")

KEEP_LANGS = {'Python', 'C++'}
KEEP_STATUS = 'Accepted'

def safe_cleanup():
    # Create new directory structure
    os.makedirs(CLEAN_DATA, exist_ok=True)
    os.makedirs(CLEAN_META, exist_ok=True)

    if not os.path.exists(ORIGINAL_META):
        print("Original Metadata path not found!")
        return

    csv_files = [f for f in os.listdir(ORIGINAL_META) if f.endswith('.csv')]
    
    for csv_file in csv_files:
        csv_path = os.path.join(ORIGINAL_META, csv_file)
        print(f"Processing: {csv_file}...")
        
        try:
            df = pd.read_csv(csv_path)
            
            # Filter logic
            filtered_df = df[
                (df['language'].isin(KEEP_LANGS)) & 
                (df['status'] == KEEP_STATUS)
            ]
            
            if filtered_df.empty:
                continue

            # 1. Save filtered CSV to the CLEAN metadata folder
            filtered_df.to_csv(os.path.join(CLEAN_META, csv_file), index=False)
            
            # 2. Copy the actual source files
            for _, row in filtered_df.iterrows():
                sub_id = row['submission_id']
                prob_id = row['problem_id']
                lang = row['language']
                ext = row['filename_ext']
                
                # Source path construction
                src_file = f"{sub_id}.{ext}"
                src_path = os.path.join(ORIGINAL_DATA, prob_id, lang, src_file)
                
                # Destination path construction
                dst_dir = os.path.join(CLEAN_DATA, prob_id, lang)
                os.makedirs(dst_dir, exist_ok=True)
                dst_path = os.path.join(dst_dir, src_file)
                
                # Copy the file (shutil.copy2 preserves metadata like timestamps)
                if os.path.exists(src_path):
                    shutil.copy2(src_path, dst_path)
                            
        except Exception as e:
            print(f"Error processing {csv_file}: {e}")

    print(f"\nSuccess! Cleaned data is now in: {CLEAN_BASE}")

if __name__ == "__main__":
    safe_cleanup()