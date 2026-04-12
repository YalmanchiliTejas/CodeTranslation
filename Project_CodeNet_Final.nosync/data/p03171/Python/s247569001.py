#!/usr/bin/env python3

import sys
sys.setrecursionlimit(10**9)
#import
#import math
#import numpy as np
N = int(input())
A = list(map(int, input().split()))

dp = [[0] * (N + 1) for _ in range(N + 1)]


for w in range(1, N + 1):
    for l in range(N - w + 1):
        r = w + l
        dp[l][r] = A[l] - dp[l + 1][r]
        if r > 0:
            dp[l][r] = max(dp[l][r], A[r - 1] - dp[l][r - 1])

print(dp[0][N])

