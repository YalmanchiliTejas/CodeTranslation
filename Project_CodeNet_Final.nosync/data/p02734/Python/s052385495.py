N, S = map(int, input().split())
mod = 998244353
A = list(map(int, input().split()))
dp1 = [[0]*(S+1) for _ in range(N+1)]
dp2 = [[0]*(S+1) for _ in range(N+1)]

for i in range(1, N+1):
    a = A[i-1]
    dp1[i][0] = 1
    for j in range(S+1):
        dp1[i][j] += dp1[i-1][j]
        dp2[i][j] = dp2[i-1][j]
        if j == a:
            dp1[i][j] += 1
        if j-a >= 0:
            dp1[i][j] += dp1[i-1][j-a]
        dp2[i][j] += dp1[i][j]
        dp1[i][j] %= mod
        dp2[i][j] %= mod

print(dp2[-1][S])
#print(dp[1])
#print(dp[2])
#print(dp[3])
