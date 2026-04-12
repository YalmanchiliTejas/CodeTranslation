MOD = 998244353
n, s = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
dp = [0] * (s + 1)
dp[0] = 1
for x in a:
    for j in range(s, x - 1, -1):
        dp[j] += dp[j - x]
        if dp[j] >= MOD:
            dp[j] -= MOD
    ans += dp[s]
    dp[0] += 1
print(ans % MOD)
