import os
import pandas as pd

def map_codenet_files(root_dir):
    data_pairs = []
    problems = [d for d in os.listdir(root_dir) if d.startswith('p')]
    
    for prob in problems:
        py_path = os.path.join(root_dir, prob, 'Python')
        cpp_path = os.path.join(root_dir, prob, 'C++')
        
        if os.path.exists(py_path) and os.path.exists(cpp_path):
            py_files = os.listdir(py_path)
            cpp_files = os.listdir(cpp_path)
            
            # Simple pairing logic: pair the first python file with the first cpp file
            # Or create a combinatorial expansion for more data
            for py_f in py_files:
                for cpp_f in cpp_files:
                    data_pairs.append({
                        'problem_id': prob,
                        'python_src': os.path.join(py_path, py_f),
                        'cpp_src': os.path.join(cpp_path, cpp_f)
                    })
    return pd.DataFrame(data_pairs)

# Usage
# df = map_codenet_files('./data')