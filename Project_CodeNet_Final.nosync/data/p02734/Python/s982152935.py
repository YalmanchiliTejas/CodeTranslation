n,s = map(int,input().split())
a = [0]+list(map(int,input().split()))
mod = 998244353
dp = [[0]*(s+1) for j in range(n+1)]
ans = 0
for i in range(1,n+1):
  if a[i] <= s:
    dp[i][a[i]] = i
  for j in range(1,s+1):
    dp[i][j] += dp[i-1][j]
    if a[i] <= j:
      dp[i][j] += dp[i-1][j-a[i]]
    dp[i][j] %= mod
  ans =  (ans + (dp[i][s]-dp[i-1][s])*(n-i+1))%mod
print(ans%mod)