#!/usr/bin/env python3
import sys
input = sys.stdin.readline

n = int(input())
s = str(n)
K = int(input())
l = len(str(n))

# dp[loose/tight][count][length]
dp = [[[0] * l for _ in range(K + 2)] for _ in range(2)]
for i, item in enumerate(s):
    val = int(item)
    # Initialize
    if i == 0:
        dp[0][0][i] = 1
        for j in range(1, 10):
            if j < val:
                dp[0][1][i] += 1
            if j == val:
                dp[1][1][i] += 1
        continue
    for j in range(10):
        is_not_zero = j != 0
        if val == j:
            for k in range(K+1):
                dp[0][k+is_not_zero][i] += dp[0][k][i-1]
                dp[1][k+is_not_zero][i] += dp[1][k][i-1]
        elif j < val:
            for k in range(K+1):
                dp[0][k+is_not_zero][i] += dp[0][k][i-1] + dp[1][k][i-1]
        else:
            for k in range(K+1):
                dp[0][k+is_not_zero][i] += dp[0][k][i-1]

print(dp[0][K][-1] + dp[1][K][-1])