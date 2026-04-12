n, s = map(int, input().split())
a = list(map(int, input().split()))
mod = 998244353

dp = [[0 for _ in range(s + 1)] for j in range(n + 1)]
dp[0][0] = 1

ans = 0
for i in range(n):
    for j in range(s + 1):
        dp[i + 1][j] += dp[i][j]
        if j >= a[i]:
            if j == a[i]:
                dp[i + 1][j] += i + 1
            else:
                dp[i + 1][j] += dp[i][j - a[i]]
    ans += dp[i + 1][s]
    ans %= mod
print(ans)
