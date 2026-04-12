N = input()
K = int(input())
L = len(N)

dp = [[[0 for j in range(L + 10)] for i in range(L + 10)] for _ in range(2)]
dp[0][0][0] = 1

for i in range(L):
    Ni = int(N[i])
    for j in range(L):
        if Ni == 0:
            dp[0][i + 1][j + 0] += dp[0][i][j + 0] * 1
            dp[0][i + 1][j + 1] += dp[0][i][j + 0] * 0
            dp[1][i + 1][j + 0] += dp[0][i][j + 0] * 0 + dp[1][i][j + 0] * 1
            dp[1][i + 1][j + 1] += dp[0][i][j + 0] * 0 + dp[1][i][j + 0] * 9
        else:
            dp[0][i + 1][j + 0] += dp[0][i][j + 0] * 0
            dp[0][i + 1][j + 1] += dp[0][i][j + 0] * 1
            dp[1][i + 1][j + 0] += dp[0][i][j + 0] * 1 + dp[1][i][j + 0] * 1
            dp[1][i + 1][j + 1] += dp[0][i][j + 0] * (Ni - 1) + dp[1][i][j + 0] * 9
#print(dp[0])
#print(dp[1])

print(dp[0][L][K] + dp[1][L][K])