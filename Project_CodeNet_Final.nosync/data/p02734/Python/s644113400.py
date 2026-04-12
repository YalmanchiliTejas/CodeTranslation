N,S = map(int,input().split())
A = list(map(int,input().split()))
MOD = 998244353

dp = [[0]*(S+1) for _ in range(N+1)]
for i,a in enumerate(A):
    dp[i+1][0] = 1
    if a <= S: dp[i+1][a] = 1
    for j in range(S+1):
        dp[i+1][j] += dp[i][j]
        dp[i+1][j] %= MOD
    for j in range(S+1):
        if j+a > S: break
        dp[i+1][j+a] += dp[i][j]
        dp[i+1][j+a] %= MOD
print(sum(row[-1] for row in dp)%MOD)