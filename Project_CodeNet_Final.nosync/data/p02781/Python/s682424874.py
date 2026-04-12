n = input()
k = int(input())

dp = [[[0, 0] for j in range(4)] for i in range(len(n)+1)]
dp[0][0][0] = 1

for i in range(len(n)):
    if int(n[i]) == 0:
        dp[i+1][0][0] = dp[i][0][0]
        dp[i+1][1][0] = dp[i][1][0]
        dp[i+1][2][0] = dp[i][2][0]
        dp[i+1][3][0] = dp[i][3][0]

    else:
        dp[i+1][1][0] = dp[i][0][0]
        dp[i+1][2][0] = dp[i][1][0]
        dp[i+1][3][0] = dp[i][2][0]
        dp[i+1][0][1] = dp[i][0][0]
        dp[i+1][1][1] = dp[i][1][0]
        dp[i+1][2][1] = dp[i][2][0]
        dp[i+1][3][1] = dp[i][3][0]

    dp[i+1][0][1] += dp[i][0][1]
    dp[i+1][1][1] += dp[i][1][1] + dp[i][0][1]*9 + dp[i][0][0]*max(int(n[i])-1, 0)
    dp[i+1][2][1] += dp[i][2][1] + dp[i][1][1]*9 + dp[i][1][0]*max(int(n[i])-1, 0)
    dp[i+1][3][1] += dp[i][3][1] + dp[i][2][1]*9 + dp[i][2][0]*max(int(n[i])-1, 0)


print(sum(dp[len(n)][k]))
