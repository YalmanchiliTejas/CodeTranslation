n = int(input())
a = list(map(int,input().split()))
dp = [[0 for i in range(3)] for j in range(n+1)]
for i in range(1,n+1):
  ai = a[i-1]
  dp[i] = dp[i-1][:]
  if i%2:
    dp[i][0] += +ai
    dp[i][1] = max(dp[i-1][0],dp[i-1][1])
  if i%2 == 0:
    dp[i][1] += ai
    dp[i][2] = max(dp[i-1][1],dp[i-1][2])
  if i >= 3 and i%2:
    dp[i][2] += ai
if n%2 == 0:
  print(max(dp[-1][0],dp[-1][1]))
else:
  print(max(dp[-1][1],dp[-1][2]))