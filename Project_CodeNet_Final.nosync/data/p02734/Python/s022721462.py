n,s = map(int,input().split())
al = list(map(int,input().split()))
MOD = 998244353

dp = [[0 for _ in range(s+1)] for _ in range(n+1)]



for i in range(n):
    for j in range(s+1):
        if j + al[i] <= s:
            dp[i+1][j+al[i]] += dp[i][j]
            dp[i + 1][j + al[i]] %= MOD
        dp[i+1][j] += dp[i][j]
        dp[i + 1][j] %= MOD
    dp[i+1][0] += 1
    dp[i + 1][0] %= MOD
    if al[i] <= s:
        dp[i+1][al[i]] += 1
        dp[i + 1][al[i]] %= MOD

ans = 0
for i in range(n+1):
    ans += dp[i][-1]
    ans %= MOD

print(ans)

# a
# b + ab
# c + bc + abc
# (1+x)
# (1+x)(1+x) + (1+x) = 2 + 3 + 1
# (1+x)(1+x)(1+x) + (1+x)(1+x) + (1+x) = 3 +
