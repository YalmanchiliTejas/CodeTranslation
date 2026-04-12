n,s = map(int,input().split())
mod = 998244353
A = list(map(int,input().split()))
dp = [0 for _ in range(s+1)]
p = 0
F = {0}
for i in range(n):
    dp[0] += 1
    x = [[j,dp[j]] for j in F]
    for j in x:
        if j[0] + A[i] <= s:
            dp[j[0] + A[i]] += j[1]
            dp[j[0] + A[i]] %= mod
            F.add(j[0] + A[i])
    p += dp[s]
    p %= mod
print(p)