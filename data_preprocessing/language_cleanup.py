import os
import shutil

# path
root_dir = "../../Project_CodeNet_Data.nosync/data"

# only python and C++
KEEP_LANGUAGES = {'Python', 'C++'}

def cleanup_codenet():
    if not os.path.exists(root_dir):
        print(f"Error: Path {root_dir} not found.")
        return

    print(f"Starting cleanup in {root_dir}...")
    
    # problem folders
    for problem_folder in os.listdir(root_dir):
        problem_path = os.path.join(root_dir, problem_folder)
        
        if os.path.isdir(problem_path):
            # lang check
            for lang_folder in os.listdir(problem_path):
                lang_path = os.path.join(problem_path, lang_folder)
                
                if os.path.isdir(lang_path):
                    if lang_folder not in KEEP_LANGUAGES:
                        try:
                            shutil.rmtree(lang_path)
                            # print(f"Deleted: {problem_folder}/{lang_folder}")
                        except Exception as e:
                            print(f"Failed to delete {lang_path}: {e}")

if __name__ == "__main__":
    cleanup_codenet()