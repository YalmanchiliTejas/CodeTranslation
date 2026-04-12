n,a,b,c,d = map(int,input().split())
mod = 10**9+7
rng = 1010
fctr = [1]
finv = [1]
for i in range(1,rng):
  fctr.append(fctr[-1]*i%mod)
for i in range(1,rng):
  finv.append(pow(fctr[i],mod-2,mod))
def cmb(n,k):
  if n<0 or k<0:
    return 0
  else:
    return fctr[n]*finv[n-k]*finv[k]%mod
wv = []
for i in range(a,b+1):
  wv.append([])
  for j in range(c,d+1):
    if i*j > n:
      continue
    v = fctr[i*j]*pow(finv[i],j,mod)*finv[j]%mod
    wv[-1].append((i*j,v))
  if wv[-1] == []:
    wv.pop()
x = len(wv)
dp = [[0 for i in range(n+1)] for j in range(x+1)]
dp[0][0] = 1
for i in range(1,x+1):
  dp[i][0] = 1
  for j in range(1,n+1):
    dp[i][j] = dp[i-1][j]
    for w,v in wv[i-1]:
      if j-w >= 0:
        dp[i][j] += dp[i-1][j-w]*v*cmb(n-(j-w),w)
      dp[i][j] %= mod
print(dp[x][n])