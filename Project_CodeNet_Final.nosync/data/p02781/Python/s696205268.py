import numpy as np
N = input()
K = int(input())
keta = len(N)
dp = np.zeros((keta + 1, 2, K + 1), dtype=np.int64)

dp[0][0][0] = 1

for i in range(1, keta + 1):
    n = int(N[i - 1])
    for j in range(K + 1):
        dp[i][1][j] += dp[i - 1][1][j]
        if j > 0:
            dp[i][1][j] += dp[i - 1][1][j - 1] * 9
        if n == 0:
            dp[i][0][j] += dp[i - 1][0][j]
        else:
            dp[i][1][j] += dp[i - 1][0][j]
            if j > 0:
                dp[i][1][j] += dp[i - 1][0][j - 1] * (n - 1)
                dp[i][0][j] += dp[i - 1][0][j - 1]

print(dp[keta][1][K] + dp[keta][0][K])