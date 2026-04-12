# coding: utf-8
N=int(input())
K=int(input())

lN=len(str(N))

dp=[[[0 for i in range(K+1)] for j in range(2)] for k in range(lN+1)]

dp[0][0][0]=1

for i in range(lN):
    num=int(str(N)[i])
    for j in range(K+1):
        if num==0:
            dp[i+1][0][j] = dp[i][0][j]
        else:
            if j==0:
                dp[i+1][0][j] = 0
            else:
                dp[i+1][0][j] = dp[i][0][j-1]
        
        if j==0:
            dp[i+1][1][j] = 1
        else:
            if num==0:
                dp[i+1][1][j] = dp[i][1][j-1]*9 + dp[i][1][j]*1
            else:
                dp[i+1][1][j] = dp[i][1][j-1]*9 + dp[i][1][j]*1 + dp[i][0][j-1]*(num-1) + dp[i][0][j]*1

print(dp[lN][1][K] + dp[lN][0][K])
