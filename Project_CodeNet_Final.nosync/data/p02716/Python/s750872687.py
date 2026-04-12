import sys
from bisect import *
from heapq import *
from collections import *
from itertools import *
from functools import *
from math import *
 
sys.setrecursionlimit(100000000)
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

dp = [{} for _ in range(N + 1)]
dp[0] = {0: 0}
dp[1] = {0: 0, 1: A[0]}

for i in range(2, N + 1):
    for j in range(max(0, i // 2 - 2), min(N, i // 2 + 2) + 1):
        candidates = []
        if j - 1 in dp[i - 2]:
            candidates.append(dp[i - 2][j - 1] + A[i - 1])
        if j in dp[i - 1]:
            candidates.append(dp[i - 1][j])
        if len(candidates) > 0:
            dp[i][j] = max(candidates)

print(dp[N][N // 2])