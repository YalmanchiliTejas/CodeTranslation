#!/bin/bash
# FILENAME: rag_eval_slurm.sh

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

module load anaconda
conda activate CS587

cd /home/$USER/cs592-eai/CodeTranslation

mkdir -p slurm_logs
mkdir -p results

export PYTHONPATH=$PWD:$PYTHONPATH

export HF_HOME=/scratch/scholar/$USER/hf_cache
export HF_HUB_CACHE=$HF_HOME/hub
export TRANSFORMERS_CACHE=$HF_HOME/transformers
export HF_DATASETS_CACHE=$HF_HOME/datasets

mkdir -p "$HF_HOME" "$HF_HUB_CACHE" "$TRANSFORMERS_CACHE" "$HF_DATASETS_CACHE"

export TOKENIZERS_PARALLELISM=false

BASE_MODEL="bigcode/starcoder2-3b"

if [ -d "checkpoints/python_to_cpp_lora_rag_k1" ]; then
  CHECKPOINT_ROOT="checkpoints/python_to_cpp_lora_rag_k1"
else
  CHECKPOINT_ROOT="checkpoints/python_to_cpp_lora_rag"
fi

echo "Running from: $(pwd)"
echo "Python: $(which python)"
echo "HF_HOME: $HF_HOME"
echo "Checkpoint root: $CHECKPOINT_ROOT"

echo "Checking test data..."
ls -lh data/test.jsonl
wc -l data/test.jsonl

echo "Checking retrieval index..."
ls -lh indexes/train.faiss
ls -lh indexes/train_meta.json

echo "Finding LoRA adapter..."
if [ -f "$CHECKPOINT_ROOT/adapter_config.json" ]; then
  MODEL_PATH="$CHECKPOINT_ROOT"
else
  ADAPTER_CONFIG=$(find "$CHECKPOINT_ROOT" -path "*/checkpoint-*/adapter_config.json" -type f | sort -V | tail -n 1 || true)

  if [ -z "$ADAPTER_CONFIG" ]; then
    echo "ERROR: No adapter_config.json found under $CHECKPOINT_ROOT"
    echo "Files found:"
    find "$CHECKPOINT_ROOT" -maxdepth 4 -type f | head -100 || true
    exit 1
  fi

  MODEL_PATH=$(dirname "$ADAPTER_CONFIG")
fi

echo "Using base model: $BASE_MODEL"
echo "Using LoRA adapter: $MODEL_PATH"

python -m translation.evaluate \
  --dataset data/test.jsonl \
  --index indexes/train.faiss \
  --meta indexes/train_meta.json \
  --model "$MODEL_PATH" \
  --base-model "$BASE_MODEL" \
  --top-k 3 \
  --repair-rounds 1 \
  --results-out results/rag_eval_results.jsonl \
  --summary-out results/rag_eval_summary.json \
  --max-examples 20 \
  --max-new-tokens 512 \
  --temperature 0.0 \
  --top-p 1.0

echo "RAG evaluation finished."
cat results/rag_eval_summary.json

echo "Scratch HF cache usage:"
du -sh /scratch/scholar/$USER/hf_cache || true
