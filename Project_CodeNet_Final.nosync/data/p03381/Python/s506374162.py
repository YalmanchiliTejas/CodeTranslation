import os
import sys

import numpy as np

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(10 ** 9)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7
# MOD = 998244353


N = int(sys.stdin.buffer.readline())
X = list(map(int, sys.stdin.buffer.readline().split()))

sorted = np.msort(X)
I = np.searchsorted(sorted, X)
if N % 2 == 1:
    ans = np.zeros(N, dtype=int)
    ans[I <= N // 2] = sorted[N // 2 + 1]
    ans[I > N // 2] = sorted[N // 2]
else:
    ans = np.zeros(N, dtype=int)
    ans[I < N // 2] = sorted[N // 2]
    ans[I >= N // 2] = sorted[N // 2 - 1]
print(*ans, sep='\n')
