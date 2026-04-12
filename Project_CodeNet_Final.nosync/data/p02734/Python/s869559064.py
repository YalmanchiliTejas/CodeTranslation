mod = 998244353
N,S = map(int,input().split())
A = list(map(int,input().split()))
dp = [[0]*(S+1) for _ in range(N)]
dp[0][0] = 1
if A[0] <= S:
    dp[0][A[0]] = 1
for i in range(1,N):
    for j in range(S+1):
        if j+A[i] <= S:
            dp[i][j+A[i]] += dp[i-1][j]
            dp[i][j+A[i]] %= mod
        dp[i][j] += dp[i-1][j]
        dp[i][j] %= mod
    dp[i][0] += 1
    dp[i][0] %= mod
    if A[i] <= S:
        dp[i][A[i]] += 1
        dp[i][A[i]] %= mod
ans = 0
for i in range(N):
    ans += dp[i][S]
ans %= mod
print(ans)