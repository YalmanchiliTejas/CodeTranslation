n, s = list(map(int, input().split()))
al = list(map(int, input().split()))
dp = [[0]*(s+1) for _ in range(n+1)]
dp[0][0] = 1
for i in range(n):
    for j in range(s+1):
        dp[i+1][j] += dp[i][j]
        if j+al[i] <= s:
            dp[i+1][j+al[i]] += dp[i][j]
        dp[i+1][j] %= 998244353
    dp[i+1][0] += 1
    if j+al[i] <= s:
        dp[i+1][al[i]] += 1
for i in range(n):
    for j in range(s+1):
        dp[i+1][j] %= 998244353
ans = 0
for i in range(n):
    ans += dp[i+1][s]
    ans %= 998244353
print(ans)
