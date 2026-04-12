N, S = map(int, input().split())
mod = 998244353
A = list(map(int, input().split()))
dp = [[0]*(S+1) for _ in range(N+1)]
for i in range(N+1):
    dp[i][0] = i+1
r = 0

for i in range(1, N+1):
    a = A[i-1]
    for j in range(1, S+1):
        dp[i][j] = dp[i-1][j]
        if j-a >= 0:
            dp[i][j] += dp[i-1][j-a]
        dp[i][j] %= mod
    r += dp[i][S]
print(r%mod)
