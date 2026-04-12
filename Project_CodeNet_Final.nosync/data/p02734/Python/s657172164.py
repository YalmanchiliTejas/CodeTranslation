n, s = map(int, input().split())
a = list(map(int, input().split()))
MOD = 998244353

dp = [[1] + [0] * s for _ in range(n + 1)]
ans = 0
for i in range(n):
    for j in range(s + 1):
        dp[i + 1][j] += dp[i][j]
        dp[i + 1][j] %= MOD
        if j + a[i] <= s:
            dp[i + 1][j + a[i]] += dp[i][j]
            dp[i + 1][j + a[i]] %= MOD
    ans += dp[i + 1][s]
    ans %= MOD

print(ans)
