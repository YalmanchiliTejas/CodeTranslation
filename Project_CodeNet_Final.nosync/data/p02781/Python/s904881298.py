N = [int(x) for x in input()]
K = int(input())
dp = [[[0]*2 for j in range(K+1)] for i in range(len(N)+1)]
dp[0][0][1] = 1
for i in range(len(N)):
    dp[i+1][0][0] = 1
    if N[i] == 0:
        for k in range(1, K+1):
            dp[i+1][k][0] = dp[i][k][0]+dp[i][k-1][0]*9
            dp[i+1][k][1] = dp[i][k][1]
    else:
        for k in range(1, K+1):
            dp[i+1][k][0] = dp[i][k][0]+dp[i][k-1][0]*9+dp[i][k-1][1]*(N[i]-1)+dp[i][k][1]
        for k in range(K-1, -1, -1):
            if dp[i][k][1]:
                dp[i+1][k+1][1] = dp[i][k][1]
                break
print(dp[len(N)][K][0]+dp[len(N)][K][1])
