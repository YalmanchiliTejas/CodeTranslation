N = input()
K = int(input())

keta = len(N)

dp = [[[0] * (K + 1) for _ in range(2)] for _ in range(keta + 1)]

dp[0][0][0] = 1

for i in range(1, keta + 1):
    for j in range(K + 1):
        if j > 0:
            dp[i][0][j] += dp[i-1][0][j-1] * (N[i-1] != '0')
            dp[i][1][j] += dp[i-1][0][j-1] * (max((int(N[i-1]) - 1),0)) + dp[i-1][1][j-1] * 9

        dp[i][0][j] += dp[i-1][0][j] * (N[i-1] == '0')
        dp[i][1][j] += dp[i-1][0][j] * (N[i-1] != '0') + dp[i-1][1][j]
        
ans = dp[keta][0][K] + dp[keta][1][K]
print(ans)