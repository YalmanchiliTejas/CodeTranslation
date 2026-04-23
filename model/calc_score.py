import os
from codebleu import calc_codebleu

def calc_score(root_dir, lang="cpp"):
    """
    Evaluates CodeBLEU for Python -> C++ translation.
    Matches first Python file to first C++ file in each problem folder as a baseline test.
    """
    references = []
    predictions = []
    
    # iterate through problem folders (p00061, p00078, etc.)
    problem_folders = [d for d in os.listdir(root_dir) if d.startswith('p')]
    
    for prob in problem_folders:
        py_dir = os.path.join(root_dir, prob, 'Python')
        cpp_dir = os.path.join(root_dir, prob, 'C++')
        
        if os.path.exists(py_dir) and os.path.exists(cpp_dir):
            py_files = sorted(os.listdir(py_dir))
            cpp_files = sorted(os.listdir(cpp_dir))
            
            if py_files and cpp_files:
                # For a baseline check, let's read the content
                with open(os.path.join(py_dir, py_files[0]), 'r', errors='ignore') as f:
                    # In a real test, 'predictions' would be your model's output
                    predictions.append(f.read()) 
                
                with open(os.path.join(cpp_dir, cpp_files[0]), 'r', errors='ignore') as f:
                    references.append(f.read())

    # Calculate CodeBLEU
    # Weights: (ngram, weighted_ngram, syntax/AST, dataflow)
    result = calc_codebleu(
        [[ref] for ref in references], 
        predictions, 
        lang=lang, 
        weights=(0.25, 0.25, 0.25, 0.25)
    )
    
    return result
