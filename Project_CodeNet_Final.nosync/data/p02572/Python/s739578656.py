import sys
import numpy as np

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

MOD = 1_000_000_007

A = np.array(read().split(), np.int64)[1:]

x = A.sum() % MOD
y = (A * A % MOD).sum() % MOD
x = (x * x - y) % MOD
if x & 1:
    x += MOD
print(x // 2)