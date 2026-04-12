s = input()
n = len(s)
d = int(input())
dp = [[[0,0] for _ in range(d)] for _ in range(n+1)]
mod = 10**9 + 7
dp[0][0][1] = 1

for i in range(n):
    for j in range(d):
        for k in range(10):
            dp[i+1][(j+k)%d][0] += dp[i][j][0]
            dp[i+1][(j+k)%d][0] %= mod
        for k in range(int(s[i])):
            dp[i+1][(j+k)%d][0] += dp[i][j][1]
            dp[i+1][(j+k)%d][0] %= mod
        dp[i+1][(j+int(s[i]))%d][1] += dp[i][j][1]
print((sum(dp[n][0])-1)%mod)
