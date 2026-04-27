#!/bin/bash
# FILENAME: train_rag_code_translation.slurm

#SBATCH --export=ALL
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --gres=gpu:1
#SBATCH --cpus-per-gpu=16
#SBATCH --mem=64G
#SBATCH --time=4:00:00
#SBATCH -J py2cpp_rag_train
#SBATCH -o slurm_logs/%j.out
#SBATCH -e slurm_logs/%j.err
#SBATCH --account=gpu

set -e

module load anaconda
conda activate translate

cd /home/tyalaman/CodeTranslation

mkdir -p slurm_logs
mkdir -p checkpoints/python_to_cpp_lora_rag

export PYTHONPATH=$PWD:$PYTHONPATH

export HF_HOME=/scratch/scholar/tyalaman/hf_cache
export HF_HUB_CACHE=$HF_HOME/hub
export TRANSFORMERS_CACHE=$HF_HOME/transformers
export HF_DATASETS_CACHE=$HF_HOME/datasets

mkdir -p "$HF_HOME" "$HF_HUB_CACHE" "$TRANSFORMERS_CACHE" "$HF_DATASETS_CACHE"

export TOKENIZERS_PARALLELISM=false
export OMP_NUM_THREADS=8

echo "Running from: $(pwd)"
echo "Python: $(which python)"
echo "HF_HOME: $HF_HOME"

echo "Checking RAG data files..."
ls -lh data/train_rag.jsonl
ls -lh data/valid_rag.jsonl
wc -l data/train_rag.jsonl
wc -l data/valid_rag.jsonl

echo "Existing RAG checkpoints:"
find checkpoints/python_to_cpp_lora_rag -maxdepth 2 -type d -name "checkpoint-*" | sort -V || true

python -m translation.train \
  --train-data data/train_rag.jsonl \
  --valid-data data/valid_rag.jsonl \
  --model bigcode/starcoder2-3b \
  --output-dir checkpoints/python_to_cpp_lora_rag \
  --use-lora \
  --bf16 \
  --gradient-checkpointing \
  --epochs 5 \
  --batch-size 1 \
  --grad-accum 8 \
  --lr 5e-5 \
  --warmup-ratio 0.05 \
  --weight-decay 0.01 \
  --max-length 2048 \
  --max-prompt-tokens 1024 \
  --max-target-tokens 896 \
  --max-problem-chars 500 \
  --max-sample-tests 1 \
  --save-steps 50 \
  --eval-steps 100 \
  --logging-steps 10 \
  --save-total-limit 3 \
  --auto-resume

echo "RAG training job finished."

echo "Current checkpoint files:"
find checkpoints/python_to_cpp_lora_rag -maxdepth 3 -type f | sort

echo "Checking for LoRA adapter files:"
find checkpoints/python_to_cpp_lora_rag -name adapter_config.json
find checkpoints/python_to_cpp_lora_rag -name adapter_model.safetensors

echo "Scratch HF cache usage:"
du -sh /scratch/scholar/tyalaman/hf_cache || true