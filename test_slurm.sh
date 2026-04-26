#!/bin/bash
# FILENAME: test_slurm.sh

#SBATCH --export=ALL
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --gres=gpu:1
#SBATCH --cpus-per-gpu=16
#SBATCH --mem=64G
#SBATCH --time=2:00:00
#SBATCH -J py2cpp_test
#SBATCH -o slurm_logs/%j.out
#SBATCH -e slurm_logs/%j.err
#SBATCH --account=gpu

set -e

module load anaconda

# Use whichever one works on your cluster:
conda activate translate
# conda activate /home/tyalaman/.conda/envs/cent7/2024.02-py311/translate

cd /home/tyalaman/CodeTranslation

mkdir -p slurm_logs
mkdir -p results

export PYTHONPATH=$PWD:$PYTHONPATH

# -----------------------------
# Hugging Face cache on scratch
# -----------------------------
export HF_HOME=/scratch/scholar/tyalaman/hf_cache
export HF_HUB_CACHE=$HF_HOME/hub
export TRANSFORMERS_CACHE=$HF_HOME/transformers
export HF_DATASETS_CACHE=$HF_HOME/datasets

mkdir -p "$HF_HOME" "$HF_HUB_CACHE" "$TRANSFORMERS_CACHE" "$HF_DATASETS_CACHE"

export TOKENIZERS_PARALLELISM=false

BASE_MODEL="bigcode/starcoder2-3b"
CHECKPOINT_ROOT="checkpoints/python_to_cpp_lora"

echo "Running from: $(pwd)"
echo "Python: $(which python)"
echo "HF_HOME: $HF_HOME"

echo "Checking test data..."
ls -lh data/test.jsonl

echo "Checking checkpoint root..."
ls -lh "$CHECKPOINT_ROOT" || true

echo "Searching for LoRA adapter_config.json..."
ADAPTER_CONFIG=$(find "$CHECKPOINT_ROOT" -name adapter_config.json -type f | sort -V | tail -n 1 || true)

if [ -z "$ADAPTER_CONFIG" ]; then
  echo "ERROR: No adapter_config.json found under $CHECKPOINT_ROOT"
  echo "This means training did not save a LoRA adapter, training failed, or the path is wrong."
  echo ""
  echo "Files found under checkpoint root:"
  find "$CHECKPOINT_ROOT" -maxdepth 4 -type f | head -100 || true
  exit 1
fi

MODEL_PATH=$(dirname "$ADAPTER_CONFIG")

echo "Using base model: $BASE_MODEL"
echo "Using LoRA checkpoint: $MODEL_PATH"
echo "Adapter config: $ADAPTER_CONFIG"

python -m translation.evaluate_codebleu \
  --test-data data/test.jsonl \
  --model "$MODEL_PATH" \
  --base-model "$BASE_MODEL" \
  --results-out results/codebleu_results.jsonl \
  --summary-out results/codebleu_summary.json \
  --bf16

echo "Evaluation finished."
echo "Scratch HF cache usage:"
du -sh /scratch/scholar/tyalaman/hf_cache || true