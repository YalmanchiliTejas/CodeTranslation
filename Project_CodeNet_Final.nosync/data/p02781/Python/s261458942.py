N = int(input())
s = "0" + str(N)
n = len(str(N))
K = int(input())

dp = [[[0] * (K+2) for _ in range(2)] for _ in range(n+1)]
dp[0][0][0] = 1

for i in range(1, n + 1):
    for k in range(K + 1):
        num = int(s[i])
        if num == 0:
            dp[i][0][k] += dp[i-1][0][k]
        else:
            dp[i][0][k] += dp[i-1][0][k-1]
            dp[i][1][k] += dp[i-1][0][k-1] * (num-1)
            dp[i][1][k] += dp[i-1][0][k]

        dp[i][1][k] += 9 * dp[i-1][1][k-1]
        dp[i][1][k] += dp[i-1][1][k]

print(dp[n][0][K] + dp[n][1][K])