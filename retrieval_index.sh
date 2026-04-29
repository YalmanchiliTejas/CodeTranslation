#!/bin/bash
# FILENAME: build_index_slurm.sh

#SBATCH --export=ALL
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --gres=gpu:1
#SBATCH --cpus-per-gpu=16
#SBATCH --time=2:00:00
#SBATCH -J py2cpp_index
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
mkdir -p indexes

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

echo "Checking train data..."
ls -lh data/train.jsonl
wc -l data/train.jsonl

echo "Building problem-aware CodeBERT retrieval index..."

python -m retrieval.index_builder \
  --input data/train.jsonl \
  --index-out indexes/train.faiss \
  --meta-out indexes/train_meta.json \
  --model-name microsoft/codebert-base \
  --batch-size 16 \
  --max-problem-chars 600 \
  --max-code-chars 1200

echo "Index built."
ls -lh indexes/train.faiss indexes/train_meta.json

echo "Scratch HF cache usage:"
du -sh "$HF_HOME" || true