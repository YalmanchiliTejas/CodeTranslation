K = input()
N = len(K)
D = int(input())
MOD = 10 ** 9 + 7

dp = [[[0 for k in range(2)] for j in range(D)] for i in range(N+1)]

dp[0][0][0] = 1
for i, n in enumerate(K):
    n = int(n)
    for j in range(D):
        for k in range(2):
            for d in range(10 if k else n+1):
                dp[i+1][(j+d) % D][k or d < n] += dp[i][j][k]
                dp[i+1][(j+d) % D][k or d < n] %= MOD

print((dp[N][0][0] + dp[N][0][1] - 1) % MOD)
