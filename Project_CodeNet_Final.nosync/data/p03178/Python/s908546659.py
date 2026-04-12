a = input()
dd = int(input())
mod = 10**9 + 7
n = len(a)
dp = [[[0 for j in range(dd)] for k in range(2)] for i in range(n+1)]
dp[0][0][0] = 1
for i in range(n):
  for j in range(2):
    for k in range(dd):
      lim = 9 if j else int(a[i]) - 0
      for d in range(lim+1):
        dp[i+1][(j or d) <lim][(k+d)%dd] += dp[i][j][k]
        dp[i+1][(j or d) <lim][(k+d)%dd] %= mod
ans = 0
for j in range(2):
  ans += dp[n][j][0]
print((ans-1)%mod)