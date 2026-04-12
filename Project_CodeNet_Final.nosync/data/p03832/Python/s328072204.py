N, A, B, C, D = map(int, input().split())
MOD = 10 ** 9 + 7

fac = [1] * (N + 1)
for i in range(2, N + 1):
    fac[i] = fac[i - 1] * i % MOD

finv = [1] * (N + 1)
finv[-1] = pow(fac[-1], MOD - 2, MOD)
for i in reversed(range(1, N + 1)):
    finv[i - 1] = finv[i] * i % MOD

dp = [[0] * (N + 1) for _ in range(B + 1)]
dp[A - 1][0] = 1

for i in range(A, B + 1):
    for j in range(N + 1):
        dp[i][j] = dp[i - 1][j]
        for k in range(C, min(D, j // i) + 1):
            t = (fac[N - j + i * k] * finv[N - j] \
                      * pow(finv[i], k, MOD) * finv[k]) % MOD
            dp[i][j] += dp[i - 1][j - i * k] * t
            dp[i][j] %= MOD

print(dp[B][N])
