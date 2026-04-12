n,a,b,c,d = map(int,input().split())

mod = 10**9 + 7
l = 2*10**6
fac = [1]*l
facr = [1]*l

for i in range(l-1):
    fac[i+1] = fac[i]*(i+1)%mod
facr[l-1] = pow(fac[l-1],mod - 2,mod)
for i in range(1,l)[::-1]:
    facr[i-1] = facr[i]*i%mod

def combi(N,K):
    return fac[N]*facr[N-K]%mod*facr[K]%mod

dp = [[0] * (n + 1) for i in range(n + 1)]

dp[0][0] = 1

for i in range(n):
    for j in range(n+1):
        dp[i + 1][j] += dp[i][j]
        dp[i + 1][j] %= mod
        if not a <= i+1 <= b: continue
        for m in range(c, d + 1):
            if j + m * (i+1) > n: break
            dp[i + 1][j + m * (i+1)] += dp[i][j] * fac[(i + 1) * m] * pow(facr[(i + 1)], m, mod) * facr[m] * combi(n-j,(i+1)*m)
            dp[i + 1][j + m * (i+1)] %= mod
print(dp[n][n] % mod)
# print(dp)
