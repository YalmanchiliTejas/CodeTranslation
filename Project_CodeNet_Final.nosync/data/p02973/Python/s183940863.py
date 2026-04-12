n = int(input())

import bisect

dp = [-1]*(n+1)

for i in range(n):
  v = int(input())
  l = bisect.bisect_left(dp, v)
  if l==n+1:
    l -= 1
  if dp[l]<v:
    dp[l] = v
  else:
    dp[l-1] = v

cnt = 0
for i in range(n, 0, -1):
  if dp[i]>=0:
    cnt += 1
  else:
    break
    
print(cnt)