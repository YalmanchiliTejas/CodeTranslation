N = str(input())
K = int(input())

dp = [ [ [ 0, 0 ]  for i in range(4) ] for j in range(len(N)+1) ]
dp[0][0][1] = 1

for i in range(1,len(N)+1):
    for j in range(4):
        for k in range(2):
            if k == 0 and j != 0:
                if N[i-1] == "0":
                    dp[i][j][k] = dp[i-1][j-1][0] * 9 + dp[i-1][j][0]
                else:
                    dp[i][j][k] = dp[i-1][j-1][0] * 9 + dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j-1][1]*(int(N[i-1])-1)
            if k == 0 and j == 0:
                dp[i][j][k] = dp[i-1][j][0] + dp[i-1][j][1]

            if k == 1 and j != 0:
                if N[i-1] == "0":
                    dp[i][j][k] = dp[i-1][j][1]
                else:
                    dp[i][j][k] = dp[i-1][j-1][1]

print(dp[len(N)][K][0] + dp[len(N)][K][1])