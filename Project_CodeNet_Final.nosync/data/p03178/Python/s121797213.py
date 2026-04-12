n = list(map(int, input()))
d = int(input())
l = len(n)
MOD = 10**9+7
dp = [[[0]*d for i in range(l+1)] for j in range(2)]
dp[0][0][0] = 1
for i in range(l):
  for j in range(d):
    for k in range(10):
      if k < n[i]:
        dp[1][i+1][j] += dp[0][i][(j-k)%d] + dp[1][i][(j-k)%d]
      elif k == n[i]:
        dp[0][i+1][j] += dp[0][i][(j-k)%d]
        dp[1][i+1][j] += dp[1][i][(j-k)%d]
      else:
        dp[1][i+1][j] += dp[1][i][(j-k)%d]
    dp[1][i+1][j] %= MOD
ans = dp[0][l][0] + dp[1][l][0] - 1
ans %= MOD
print(ans)