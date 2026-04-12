N, A, B, C, D = map(int, input().split())


MOD = 10 ** 9 + 7
M = 1005
fact = [0] * M
fact[0] = 1
for i in range(1, M):
    fact[i] = fact[i - 1] * i
    fact[i] %= MOD

rfact = [0] * M
rfact[M - 1] = pow(fact[M - 1], MOD - 2, MOD)
for i in range(M - 2, -1, -1):
    rfact[i] = rfact[i + 1] * (i + 1)
    rfact[i] %= MOD

dp = [[0] * (N + 1) for i in range(N + 1)]
dp[A - 1][0] = 1
for i in range(A, B + 1):
    for j in range(N + 1):
        dp[i][j] += dp[i - 1][j]
        k = C
        while k <= D and j - k * i >= 0:
            dp[i][j] += dp[i - 1][j - k * i] * fact[N - (j - k * i)] * pow(rfact[i], k, MOD) * rfact[k] * rfact[N - j]
            dp[i][j] %= MOD
            k += 1

print(dp[B][N])
