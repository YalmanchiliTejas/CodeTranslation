n = input()
k = int(input())

dp = [[0] * (k + 2) for _ in range(2)]
dp[0][0] = 1

for d in n:
    ndp = [[0] * (k + 2) for _ in range(2)]
    for i in range(k + 1):
        ndp[1][i] += dp[1][i]
        ndp[1][i + 1] += dp[1][i] * 9
        if d == '0':
            ndp[0][i] += dp[0][i]
        else:
            ndp[1][i] += dp[0][i]
            ndp[1][i + 1] += dp[0][i] * (int(d) - 1)
            ndp[0][i + 1] += dp[0][i]
    dp = ndp
print(dp[0][k] + dp[1][k])
