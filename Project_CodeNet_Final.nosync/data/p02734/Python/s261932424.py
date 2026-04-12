n, s = map(int, input().split())
a = list(map(int, input().split()))
dp = [[k + 1] + [0] * s for k in range(n + 1)] #dp[i][j] : 左からi個使ってぴったりj
for i in range(1, n + 1):
    for j in range(1, s + 1):
        if j - a[i - 1] < 0:
            dp[i][j] = dp[i - 1][j] % 998244353
        else:
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - a[i - 1]]) % 998244353
ans = 0
for i in range(1, n + 1):
    ans += dp[i][s]
    ans %= 998244353
print(ans)