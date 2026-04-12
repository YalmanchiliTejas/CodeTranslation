n, s = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
mod = 998244353

dp = [[0] * (s + 1) for _ in range(n + 1)]
dp[0][0] = 1

for i in range(n):
    dp[i][0] = i + 1
    for j in range(1, s + 1):
        if j >= a[i]:
            dp[i+1][j] += dp[i][j-a[i]]
        dp[i + 1][j] += dp[i][j]
        dp[i + 1][j] %= mod

ans = 0
for i in range(1, n + 1):
    ans += dp[i][-1] * 1#(n + 1 - i)
    ans %= mod
print(ans)
