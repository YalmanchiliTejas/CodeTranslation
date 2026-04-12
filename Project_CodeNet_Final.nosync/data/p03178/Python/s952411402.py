K = input()
D = int(input())
N = len(K)
mod = 10**9+7

dp0 = [[0] * D for _ in range(N+1)]
dp1 = [[0] * D for _ in range(N+1)]
dp0[0][0] = 1
for i in range(N):
    k = int(K[i])
    for j in range(D):
        dp0[i+1][(j+k)%D] = (dp0[i+1][(j+k)%D] + dp0[i][j]) % mod
        dp1[i+1][(j+k)%D] = (dp1[i+1][(j+k)%D] + dp1[i][j]) % mod
        for k_ in range(k):
            dp1[i+1][(j+k_)%D] = (dp1[i+1][(j+k_)%D] + dp0[i][j] + dp1[i][j]) % mod
        for k_ in range(k+1, 10):
            dp1[i + 1][(j + k_) % D] = (dp1[i + 1][(j + k_) % D] + dp1[i][j]) % mod

print((dp0[-1][0] + dp1[-1][0] - 1) % mod)
