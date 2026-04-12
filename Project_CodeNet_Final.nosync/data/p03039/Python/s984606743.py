import sys
input = sys.stdin.readline
import math

N, M, K = [int(item) for item in input().split()]
mod = 10**9 + 7

score_c = 1
for i in range(2, K):
    score_c *= ((N * M - i) % mod * pow(K - i, mod - 2, mod))
    score_c %= mod

total = 0
for d in range(1, N):
    score = (N - d) * M**2 * d * score_c
    score %= mod
    total += score
    total %= mod

for d in range(1, M):
    score = (M - d) * N**2 * d * score_c
    score %= mod
    total += score
    total %= mod


print(total)
