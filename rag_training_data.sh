#!/bin/bash

# FILENAME: rag_training_data.sh

#SBATCH --export=ALL
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --gres=gpu:1
#SBATCH --cpus-per-gpu=16
#SBATCH --mem=64G
#SBATCH --time=4:00:00
#SBATCH -J py2cpp_rag_eval
#SBATCH -o slurm_logs/%j.out
#SBATCH -e slurm_logs/%j.err
#SBATCH --account=gpu

set -e

cd /home/$USER/cs592-eai/CodeTranslation

export PYTHONPATH=$PWD:$PYTHONPATH

export HF_HOME=/scratch/scholar/$USER/hf_cache
export HF_HUB_CACHE=$HF_HOME/hub
export TRANSFORMERS_CACHE=$HF_HOME/transformers
export HF_DATASETS_CACHE=$HF_HOME/datasets

mkdir -p "$HF_HOME" "$HF_HUB_CACHE" "$TRANSFORMERS_CACHE" "$HF_DATASETS_CACHE"

export TOKENIZERS_PARALLELISM=false

python -m data_preprocessing.create_rag_training_data \
  --input data/train.jsonl \
  --output data/train_rag.jsonl \
  --index indexes/train.faiss \
  --meta indexes/train_meta.json \
  --top-k 3

python -m data_preprocessing.create_rag_training_data \
  --input data/valid.jsonl \
  --output data/valid_rag.jsonl \
  --index indexes/train.faiss \
  --meta indexes/train_meta.json \
  --top-k 3

echo "Done creating RAG training data."
du -sh /scratch/scholar/$USER/hf_cache