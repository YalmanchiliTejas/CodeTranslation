n,s = map(int,input().split())
a = list(map(int,input().split()))
dp1 = [[0 for i in range(s+1)] for j in range(n+1)]
dp2 = [[0 for i in range(s+1)] for j in range(n+1)]
mod = 998244353
dp1[0][0] = 1
for i in range(1,n+1):
  x = a[i-1]
  for j in range(1,s+1):
    p = 0
    q = 0
    if j == x:
      p += i
      q += i*(n-i+1)
    if j>x:
      dif = dp1[i-1][j-x]
      p = dif
      q = dif*(n+1-i)
    p += dp1[i-1][j]
    q += dp2[i-1][j]
    dp1[i][j] = p%mod
    dp2[i][j] = q%mod
print(dp2[n][s])