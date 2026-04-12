k = input()
d = int(input())
mod = 10**9+7

dp = [[[0]*2 for i in range(d)] for j in range(len(k)+1)]

dp[0][0][1] = 1
for i in range(len(k)):
    s = int(k[i])
    for j in range(10):
        for m in range(d):
            if s == j:
                dp[i+1][(m+j)%d][1] += dp[i][m][1]
                dp[i+1][(m+j)%d][1] %= mod
            elif s > j:
                dp[i+1][(m+j)%d][0] += dp[i][m][1]
                dp[i+1][(m+j)%d][0] %= mod
            dp[i+1][(m+j)%d][0] += dp[i][m][0]
            dp[i+1][(m+j)%d][0] %= mod

print((sum(dp[-1][0])-1)%mod)