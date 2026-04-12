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

N, K = [int(sys.stdin.buffer.readline()) for _ in range(2)]
N = str(N)

DIGIT = len(N)
# d から K 個選ぶ
dp = np.zeros((DIGIT + 1, K + 1, 2), dtype=int)
dp[0, 0, 0] = 1
for d in range(1, DIGIT + 1):
    nd = int(N[d - 1])
    if nd > 0:
        dp[d, :, 1] += dp[d - 1, :, 0]
        dp[d, :, 1] += dp[d - 1, :, 1]
        for k in range(1, K + 1):
            # この d で 1 個使う
            dp[d][k][0] += dp[d - 1][k - 1][0]
            dp[d][k][1] += dp[d - 1][k - 1][0] * (nd - 1)
            dp[d][k][1] += dp[d - 1][k - 1][1] * 9
    else:
        dp[d, :, 0] += dp[d - 1, :, 0]
        dp[d, :, 1] += dp[d - 1, :, 1]
        for k in range(1, K + 1):
            # この d で 1 個使う
            dp[d][k][1] += dp[d - 1][k - 1][1] * 9
print(dp[-1][K].sum())
