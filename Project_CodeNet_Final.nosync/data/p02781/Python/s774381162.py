n = str(input())
k = int(input())
dp = [[[0] * (k+1) for i in range(2)] for j in range(len(n)+1)]
dp[0][0][0] = 1
for i in range(len(n)):
    for j in range(k+1):
        if n[i] == "0":
            dp[i+1][0][j] = dp[i][0][j]
            dp[i+1][1][j] = dp[i][1][j]
            if j > 0:
                dp[i+1][1][j] += dp[i][1][j-1]*9
        else:
            dp[i+1][1][j] = dp[i][0][j] + dp[i][1][j]
            if j > 0:
                dp[i+1][0][j] = dp[i][0][j-1]
                dp[i+1][1][j] += dp[i][0][j-1] * (int(n[i])-1) + dp[i][1][j-1] * 9
  # print(dp)
print(dp[-1][0][k] + dp[-1][1][k])