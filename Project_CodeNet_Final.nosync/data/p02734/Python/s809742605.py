n, s = map(int, input().split())
a = list(map(int, input().split()))
MOD = 998244353

dp = [0] * (3000 + 1)
dp[0] = 1
ans = 0
for i in range(n):
    for w in range(3000 + 1)[::-1]:
        # 選ぶとき
        if w - a[i] > 0:
            dp[w] += dp[w - a[i]]
        if w - a[i] == 0:
            dp[w] += dp[w - a[i]] * (i + 1)
        dp[w] %= MOD
    ans += dp[s]
    ans %= MOD
print(ans % MOD)