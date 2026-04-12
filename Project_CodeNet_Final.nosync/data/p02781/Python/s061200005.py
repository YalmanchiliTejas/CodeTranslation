#!/usr/bin/env python3
n = input()
N = len(n)
k = int(input())
dp = [[[0] * 2 for j in range(k + 1)] for i in range(N + 1)]
dp[0][0][0] = 1
for i in range(N):
    for j in range(k + 1):
        d = int(n[i])
        
        # i 桁目に "0" を配置したとき
        if d > 0:
            dp[i + 1][j][1] += dp[i][j][0]
        else:
            dp[i + 1][j][0] += dp[i][j][0]
        dp[i + 1][j][1] += dp[i][j][1]

        # i 桁目に "1", ..., "9" を配置したとき
        if j < k:
            if d > 0:
                dp[i + 1][j + 1][0] += dp[i][j][0]
                dp[i + 1][j + 1][1] += dp[i][j][0] * (d - 1)
            dp[i + 1][j + 1][1] += dp[i][j][1] * 9

print(dp[N][k][0] + dp[N][k][1])
