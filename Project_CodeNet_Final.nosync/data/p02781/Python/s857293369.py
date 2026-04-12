N = [int(i) for i in str(input())]
m = len(N)
K = int(input())
dp = [[[0 for i in range(K + 1)],[0 for i in range(K + 1)]]   for i in range(m)]
#初期条件
dp[0][1][0] = 1
dp[0][0][1] = 1
dp[0][1][1] = N[0] - 1
for i in range(1,m):
    for t in range(0,min(i+2,K+1)):
        if N[i] != 0:
            if t == 0:
                dp[i][1][t] = dp[i-1][1][t]
            else:
                dp[i][0][t] = dp[i-1][0][t-1]
                dp[i][1][t] = dp[i-1][0][t] + dp[i-1][0][t-1] * (N[i]-1) + dp[i-1][1][t] + dp[i-1][1][t-1] * 9
        else :
            if t == 0:
                dp[i][0][t] = dp[i-1][0][t]
                dp[i][1][t] = dp[i-1][1][t] 
            else :
                dp[i][0][t] = dp[i-1][0][t]
                dp[i][1][t] = dp[i-1][1][t] + dp[i-1][1][t-1] * 9
print(dp[-1][0][K]+dp[-1][1][K])