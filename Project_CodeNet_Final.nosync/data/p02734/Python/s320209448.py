import sys
input = sys.stdin.readline

mod = 998244353

N,S = map(int,input().split())
A = list(map(int,input().split()))

dp0 = [[0]*(S+1) for _ in range(N+1)]
dp1 = [[0]*(S+1) for _ in range(N+1)]
dp2 = [[0]*(S+1) for _ in range(N+1)]
###dp[i][j][k]:Aのindex[i-1]まで見て和がjになっているもの
###kの意味は解説の通り


dp0[0][0] = 1

for i in range(N):
    for j in range(S+1):
        dp0[i+1][j] += dp0[i][j]
        dp0[i+1][j] %= mod

        dp1[i+1][j] += dp0[i][j] + dp1[i][j]
        dp1[i+1][j] %= mod

        dp2[i+1][j] += dp0[i][j] + dp1[i][j] + dp2[i][j]
        dp2[i+1][j] %= mod

        if j+A[i] <= S:
            dp1[i+1][j+A[i]] += dp0[i][j] + dp1[i][j]
            dp1[i+1][j+A[i]] %= mod
        
            dp2[i+1][j+A[i]] += dp0[i][j] + dp1[i][j]
            dp2[i+1][j+A[i]] %= mod

print(dp2[N][S])