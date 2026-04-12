n = int(input())
k = int(input())
len_n = len(str(n))
dp = [[[0] * (k + 1) for i in range(2)] for j in range(len_n + 1)]
dp[0][0][0] = 1

for i in range(1, len_n + 1):
    l = int(str(n)[i - 1])
    for m in range(k + 1):
        dp[i][1][m] += dp[i - 1][1][m]
        if l != 0:
            dp[i][1][m] += dp[i - 1][0][m]
        else:
            dp[i][0][m] += dp[i - 1][0][m]
        if m - 1 >= 0:
            dp[i][1][m] += 9 * dp[i - 1][1][m - 1]
            if l != 0:
                dp[i][0][m] += dp[i - 1][0][m - 1]
                dp[i][1][m] += (l - 1) * dp[i - 1][0][m - 1]

print(dp[len_n][0][k] + dp[len_n][1][k])