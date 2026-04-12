n, a, b, c, d = map(int, raw_input().split())
MOD = 10**9+7
fact = [1]*(n+1)
frev = [1]*(n+1)

rcd = range(c, d+1)

dp = [0]*(n+1)
dp[0] = 1

for i in xrange(1, n+1):
    v = fact[i] = (fact[i-1] * i) % MOD
    frev[i] = pow(v, MOD-2, MOD)
if a==c==1 and b==d==n:
    Y = [None]*(n+1)
    for g in xrange(1, n+1):
        y = frev[g]
        Y[g:n+1:g] = (pow(y, j, MOD)*frev[j] for j in xrange(1, n/g+1))
        dp[g:] = (dp[i] + frev[n-i]*sum(dp[i-j] * fact[n-i+j] * Y[j] for j in xrange(g, i+1, g)) % MOD for i in xrange(g, n+1))
else:
    Y = [None]*(d+1-c)
    for g in xrange(a, min(n/c, b)+1):
        p = c*g
        y = frev[g]
        Y[:min(d,n/g)+1-c] = (pow(y, j, MOD)*frev[j] for j in xrange(c, min(d, n/g)+1))
        dp[p:] = (dp[i] + frev[n-i]*sum(dp[i-g*j] * fact[n-i+g*j] * Y[j-c] for j in xrange(c, min(d, i/g)+1)) % MOD for i in xrange(p, n+1))
print dp[n]%MOD