N, S = map(int, input().split())
mod = 998244353
A = list(map(int, input().split()))
dp1 = [[0]*(S+1) for _ in range(N+1)]
r = 0

for i in range(1, N+1):
    a = A[i-1]
    dp1[i][0] = 1
    for j in range(S+1):
        dp1[i][j] += dp1[i-1][j]
        if j == a:
            dp1[i][j] += 1
        if j-a >= 0:
            dp1[i][j] += dp1[i-1][j-a]
        dp1[i][j] %= mod
    r += dp1[i][S]
print(r%mod)
