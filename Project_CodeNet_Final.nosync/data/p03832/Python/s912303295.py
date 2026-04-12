MOD = 10 ** 9 + 7
M = 10 ** 3 + 7

N, A, B, C, D = map(int, input().split())

fact = [1] * M
inv = [1] * M
def mod_inv():
    for i in range(2, M):
        fact[i] = i * fact[i-1] % MOD
    inv[M-1] = pow(fact[M-1], MOD - 2, MOD)
    for i in range(M-1, 0, -1):
        inv[i-1] = i * inv[i] % MOD
mod_inv()

def nCr(n, r):
    if r > n // 2:
        r = n - r
    return fact[n] * inv[n-r] * inv[r] % MOD

dp = [[0] * M for _ in range(B+2)]
dp[A][0] = 1

for i in range(A, B+1):
    for j in range(N+1):
        p = 1
        l = (N - j) // i
        for k in range(min(D, l) + 1):
            if k == 0 or C <= k:
                dp[i+1][j+i*k] += p * dp[i][j] * inv[k]
                dp[i+1][j+i*k] %= MOD
            p *= nCr(N-i*k-j, i)
            p %= MOD
print(dp[B+1][N])