#!/bin/bash
# FILENAME: train_code_translation.slurm

#SBATCH --export=ALL
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --gres=gpu:2
#SBATCH --cpus-per-gpu=16

#SBATCH --time=4:00:00
#SBATCH -J py2cpp_train
#SBATCH -o slurm_logs/%j.out
#SBATCH -e slurm_logs/%j.err
#SBATCH --account=gpu

set -e

module load anaconda
conda activate translate

cd /home/tyalaman/CodeTranslation

mkdir -p slurm_logs
mkdir -p checkpoints/python_to_cpp_lora

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
ls -lh data/train.jsonl
ls -lh data/valid.jsonl
wc -l data/train.jsonl
wc -l data/valid.jsonl

python -m translation.train \
  --train-data data/train.jsonl \
  --valid-data data/valid.jsonl \
  --model bigcode/starcoder2-3b \
  --output-dir checkpoints/python_to_cpp_lora \
  --use-lora \
  --bf16 \
  --epochs 3 \
  --batch-size 1 \
  --grad-accum 16 \
  --lr 1e-4 \
  --max-length 4096

echo "Training finished."
find checkpoints/python_to_cpp_lora -maxdepth 3 -type f | sort
find checkpoints/python_to_cpp_lora -name adapter_config.json
find checkpoints/python_to_cpp_lora -name adapter_model.safetensors
du -sh /scratch/scholar/tyalaman/hf_cache || true