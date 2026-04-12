# coding: utf-8
import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N, S = lr()
A = lr()
MOD = 998244353
dp = [0] * (S+1)

answer = 0
for a in A:
    dp[0] += 1
    for x in range(S, a-1, -1):
        dp[x] += dp[x-a]
    answer += dp[-1]
    answer %= MOD

print(answer%MOD)
