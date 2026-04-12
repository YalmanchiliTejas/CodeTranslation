#!/usr/bin/env python3
import sys
input = sys.stdin.readline
INF = 10**9

n = input().rstrip()
k = int(input())

# dp[tight-loose][k][i-th item]
dp = [[[0] * len(n) for _ in range(k+1)] for _ in range(2)]

for i, ch in enumerate(n): 
    item = int(ch)
    if i == 0:
        # tight -> tight
        dp[0][1][0] = 1
        # tight -> loose with 0
        dp[1][0][0] = 1
        # tight -> loose without 0
        dp[1][1][0] = max(0, item - 1)
        continue
    for j in range(k+1):
        if item != 0:
            # tight -> loose with 0
            dp[1][j][i] += dp[0][j][i-1]
            # loose -> loose with 0
            dp[1][j][i] += dp[1][j][i-1]
            if j < k:
                # tight -> tight
                dp[0][j+1][i] += dp[0][j][i-1] 
                # tight -> loose without 0
                dp[1][j+1][i] += dp[0][j][i-1] * max(0, (item - 1))
                # loose -> loose without 0
                dp[1][j+1][i] += dp[1][j][i-1] * 9 
        else:
            # tight -> tight with 0
            dp[0][j][i] += dp[0][j][i-1] 
            # loose -> loose with 0
            dp[1][j][i] += dp[1][j][i-1] 
            if j < k:
                # loose -> loose without 0
                dp[1][j+1][i] += dp[1][j][i-1] * 9

print(dp[0][k][-1] + dp[1][k][-1])