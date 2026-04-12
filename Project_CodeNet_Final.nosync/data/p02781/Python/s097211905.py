n = input()
K = int(input())
L = len(n)

dp = [[[0] * (K + 2) for _ in range(2)] for __ in range(L + 1)]
dp[0][1][0] = 1

for i in range(L):
    d = int(n[i])
    for j in [0, 1]:
        for k in range(K + 1):
            if j == 0:
                dp[i + 1][j][k] += dp[i][j][k]
                dp[i + 1][j][k + 1] += dp[i][j][k] * 9
            else:
                if d > 0:
                    dp[i + 1][0][k] += dp[i][j][k]
                    dp[i + 1][0][k + 1] += dp[i][j][k] * (d - 1)
                    dp[i + 1][1][k + 1] += dp[i][j][k]
                else:
                    dp[i + 1][1][k] += dp[i][j][k]


print(dp[L][0][K] + dp[L][1][K])

