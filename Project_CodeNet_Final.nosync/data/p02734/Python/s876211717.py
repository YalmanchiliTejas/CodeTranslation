import sys
input = sys.stdin.readline
N, S = map(int, input().split())
a = list(map(int, input().split()))
mod = 998244353
dp = [0] * (S + 1)
for l in range(N):
  r = N - l
  x = a[l]
  if x > S: continue
  for i in range(S, 0, -1):
    if i + x > S: continue
    if i + x == S:
      dp[S] += dp[i] * r
      dp[S] %= mod
    else:
      dp[i + x] += dp[i]
      dp[i + x] %= mod
  if x == S:
    dp[S] += (l + 1) * r
    dp[S] %= mod
  else:
    dp[x] += l + 1
    dp[x] %= mod
  #print(dp)
print(dp[-1])