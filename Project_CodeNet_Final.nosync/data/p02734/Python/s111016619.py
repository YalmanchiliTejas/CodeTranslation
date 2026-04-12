N,S = map(int,input().split())
A = list(map(int,input().split()))
mod = 998244353

dp = [0] * (S+1)
ans = 0
for i in range(N):
    ndp = dp[:]
    if A[i] <= S:
        ndp[A[i]] = (ndp[A[i]] + i+1) % mod
    for j in range(S):
        if j+A[i] <= S:
            ndp[j+A[i]] = (ndp[j+A[i]] + dp[j]) % mod
    ans = (ans + ndp[S]) % mod
    dp = ndp[:]
print (ans)
