n, s = map(int, input().split())
a = [int(x) for x in input().split()]
mod = 998244353

dp = [[0 for _ in range(s+1)] for __ in range(n+1)]

dp[0][0] = 1

for i in range(n):
    for j in range(s+1):
        dp[i+1][j] += dp[i][j]
        if j-a[i] == 0:
            dp[i+1][j] += i+1
        elif j-a[i] >= 0:
            dp[i+1][j] += dp[i][j-a[i]]
        dp[i+1][j] %= mod

ans = 0

for i in range(n+1):
    ans += dp[i][s]
    ans %= mod

print(ans)
