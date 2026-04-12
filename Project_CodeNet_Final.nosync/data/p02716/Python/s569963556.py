# coding: utf-8

N=int(input())
A=list(map(int,input().split()))
INF=10**18

dp=[[-INF for i in range(2)] for j in range(N+1)]
dp[0][0]=0
dp[1][0]=0
dp[2][0]=0
dp[1][1]=A[0]
dp[2][1]=A[1]

for i in range(3,N+1):
    dp[i][0]=max(dp[i-2][0]+A[i-1],dp[i-2][1])
    if i%2==0:
        dp[i][0]=max(dp[i][0],dp[i-3][0]+A[i-1])
    else:
        dp[i][0]=max(dp[i][0],dp[i-3][1]+A[i-1])
    
    dp[i][1]=dp[i-2][1]+A[i-1]
    if i%2==0:
        dp[i][1]=max(dp[i][1],dp[i-3][1]+A[i-1])

if N%2==0:
    print(max(dp[N][1],dp[N-1][1]))
else:
    print(max(dp[N][0],dp[N-1][1],dp[N-2][1]))
