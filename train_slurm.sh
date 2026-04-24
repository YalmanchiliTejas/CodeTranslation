#!/bin/bash
# FILENAME: train_code_translation.slurm

#SBATCH --export=ALL
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --gres=gpu:1
#SBATCH --cpus-per-gpu=16
#SBATCH --mem=64G
#SBATCH --time=4:00:00
#SBATCH -J py2cpp_train
#SBATCH -o slurm_logs/%j.out
#SBATCH -e slurm_logs/%j.err
#SBATCH --account=gpu

# -----------------------------
# Environment setup
# -----------------------------
module load anaconda
conda activate CS587

# Change this to your actual project path
# cd /home/venkat97/CodeTranslation
cd /home/tyalaman/CodeTranslation

mkdir -p slurm_logs
mkdir -p checkpoints/python_to_cpp_lora

# Optional but useful for Hugging Face cache on clusters
export HF_HOME=$PWD/.hf_cache
export TRANSFORMERS_CACHE=$HF_HOME/transformers
export HF_DATASETS_CACHE=$HF_HOME/datasets

# Avoid tokenizer parallelism warnings
export TOKENIZERS_PARALLELISM=false

# -----------------------------
# Training command
# -----------------------------
python -m translation.train \
  --train-data data/train.jsonl \
  --valid-data data/valid.jsonl \
  --model bigcode/starcoder2-3b \
  --output-dir checkpoints/python_to_cpp_lora \
  --use-lora \
  --bf16 \
  --epochs 1 \
  --batch-size 1 \
  --grad-accum 8 \
  --lr 2e-4 \
  --max-length 4096