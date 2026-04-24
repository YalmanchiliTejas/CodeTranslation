#!/bin/bash
# FILENAME: eval_codebleu.slurm

#SBATCH --export=ALL
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --gres=gpu:1
#SBATCH --cpus-per-gpu=16
#SBATCH --mem=64G
#SBATCH --time=2:00:00
#SBATCH -J py2cpp_eval
#SBATCH -o slurm_logs/%j.out
#SBATCH -e slurm_logs/%j.err
#SBATCH --account=gpu

module load anaconda
conda activate CS587

cd /home/venkat97/CodeTranslation
# cd /home/tyalaman/CodeTranslation

mkdir -p slurm_logs
mkdir -p results

export HF_HOME=$PWD/.hf_cache
export TRANSFORMERS_CACHE=$HF_HOME/transformers
export HF_DATASETS_CACHE=$HF_HOME/datasets
export TOKENIZERS_PARALLELISM=false

python -m translation.evaluate_codebleu \
  --test-data data/test.jsonl \
  --model checkpoints/python_to_cpp_lora \
  --results-out results/codebleu_results.jsonl \
  --summary-out results/codebleu_summary.json \
  --bf16