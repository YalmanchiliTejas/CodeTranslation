N, S = map(int, input().split())
A = list(map(int, input().split()))
MOD = 998244353
dp = [[0]*(S+1) for _ in range(N+1)]
dp[0][0] = 1

for i in range(N):
    for j in range(S):
        dp[i+1][j] += dp[i][j]
        
        if j+A[i]<=S:
            dp[i+1][j+A[i]] += dp[i][j]
            
            if j==0:
                dp[i+1][j+A[i]] += i
        
    for j in range(S+1):
        dp[i+1][j] %= MOD

ans = 0

for i in range(1, N+1):
    ans += dp[i][S]*(N-i+1)
    ans %= MOD

print(ans)