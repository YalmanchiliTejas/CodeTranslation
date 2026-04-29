#!/bin/bash
# FILENAME: rag_training_data.sh

#SBATCH --export=ALL
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --gres=gpu:1
#SBATCH --cpus-per-gpu=16

#SBATCH --time=2:00:00
#SBATCH -J py2cpp_rag_data
#SBATCH -o slurm_logs/%j.out
#SBATCH -e slurm_logs/%j.err
#SBATCH --account=gpu

set -e

module load anaconda
conda activate translate
# conda activate CS587

cd /home/tyalaman/CodeTranslation
# cd /home/$USER/cs592-eai/CodeTranslation

mkdir -p slurm_logs

export PYTHONPATH=$PWD:$PYTHONPATH

export HF_HOME=/scratch/scholar/$USER/hf_cache
export HF_HUB_CACHE=$HF_HOME/hub
export TRANSFORMERS_CACHE=$HF_HOME/transformers
export HF_DATASETS_CACHE=$HF_HOME/datasets

mkdir -p "$HF_HOME" "$HF_HUB_CACHE" "$TRANSFORMERS_CACHE" "$HF_DATASETS_CACHE"

export TOKENIZERS_PARALLELISM=false

echo "Running from: $(pwd)"
echo "Python: $(which python)"
echo "HF_HOME: $HF_HOME"

echo "Checking input files..."
ls -lh data/train.jsonl
ls -lh data/valid.jsonl
ls -lh indexes/train.faiss
ls -lh indexes/train_meta.json

echo "Creating top-k=1 RAG training data..."

python -m data_preprocessing.create_rag_training_data \
  --input data/train.jsonl \
  --output data/train_rag_k1.jsonl \
  --index indexes/train.faiss \
  --meta indexes/train_meta.json \
  --top-k 1

python -m data_preprocessing.create_rag_training_data \
  --input data/valid.jsonl \
  --output data/valid_rag_k1.jsonl \
  --index indexes/train.faiss \
  --meta indexes/train_meta.json \
  --top-k 1

echo "Done creating RAG training data."
ls -lh data/train_rag_k1.jsonl
ls -lh data/valid_rag_k1.jsonl
wc -l data/train_rag_k1.jsonl
wc -l data/valid_rag_k1.jsonl

echo "Checking retrieved_examples count..."
python - <<'PY'
import json

for path in ["data/train_rag_k1.jsonl", "data/valid_rag_k1.jsonl"]:
    total = 0
    with_rag = 0

    with open(path) as f:
        for line in f:
            r = json.loads(line)
            total += 1
            if r.get("retrieved_examples"):
                with_rag += 1

    print(path, "total:", total, "with_rag:", with_rag)
PY

echo "Scratch HF cache usage:"
du -sh "$HF_HOME" || true