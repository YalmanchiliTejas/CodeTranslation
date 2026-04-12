import math

K=input()
D=int(input())
n=len(K)
dp=[[[0 for _ in range(D)] for _ in range(2)] for _ in range(n+1)]
MOD=10**9+7

dp[0][0][0]=1
for i in range(0,n):
    a=int(K[i])
    x=a%D
    for j in range(D):
        for x in range(10):
            dp[i+1][1][(j+x)%D]=(dp[i+1][1][(j+x)%D]+dp[i][1][j])%MOD
        for x in range(a):
            dp[i+1][1][(j+x)%D]=(dp[i+1][1][(j+x)%D]+dp[i][0][j])%MOD
        dp[i+1][0][(j+a)%D]=dp[i][0][j]

print((dp[n][0][0]+dp[n][1][0]-1)%MOD)
