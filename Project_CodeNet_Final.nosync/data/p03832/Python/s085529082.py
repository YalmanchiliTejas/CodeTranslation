n, a, b, c, d = map(int, raw_input().split())
dp = [0]*(n+1)
dp[0] = 1

MOD = 10**9+7
fact = [1]*(n+1)
frev = [1]*(n+1)

rn = range(n, -1, -1)

for i in xrange(1, n+1):
    fact[i] = (fact[i-1] * i) % MOD
    frev[i] = pow(fact[i], MOD-2, MOD)
for g in xrange(a, b+1):
    y = frev[g]
    for i in rn:
        x = frev[n-i]
        dp[i] = (dp[i] + sum(dp[i-g*j] * fact[n-i+g*j] * x * pow(y, j, MOD) * frev[j] for j in xrange(c, min(d, i/g)+1))) % MOD
print dp[n]
