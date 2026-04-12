import os
import sys

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(10 ** 9)
INF = float("inf")
IINF = 10 ** 18
# MOD = 10 ** 9 + 7
MOD = 998244353

# 解説
N, S = list(map(int, sys.stdin.buffer.readline().split()))
A = list(map(int, sys.stdin.buffer.readline().split()))

# dp[i][k]: iまで見て、合計がkの場合の数
dp = [[0] * S for _ in range(N + 1)]
ans = 0
for i in range(N):
    for k in range(S):
        dp[i + 1][k] += dp[i][k]
        dp[i + 1][k] %= MOD
        if k == 0 and k + A[i] < S:
            # ここから使う
            # L の選び方が i + 1 ある
            dp[i + 1][A[i]] += i + 1
            dp[i + 1][A[i]] %= MOD
        elif k == 0 and k + A[i] == S:
            ans += (i + 1) * (N - i)
        elif k + A[i] < S:
            dp[i + 1][k + A[i]] += dp[i][k]
            dp[i + 1][k + A[i]] %= MOD
        elif k + A[i] == S:
            # ここまで使う
            # R の選び方が N - i ある
            ans += dp[i][k] * (N - i)
        ans %= MOD
print(ans)
