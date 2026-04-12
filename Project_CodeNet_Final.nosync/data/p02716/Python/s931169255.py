n = int(input())
a = list(map(int,input().split()))
dp = [0 for i in range(3)]
for i in range(1,n+1):
  ai = a[i-1]
  if i%2:
    dp[1] = max(dp[0],dp[1])
    dp[0] += ai
  if i%2 == 0:
    dp[2] = max(dp[1],dp[2])
    dp[1] += ai
  if i >= 3 and i%2:
    dp[2] += ai
if n%2 == 0:
  print(max(dp[0],dp[1]))
else:
  print(max(dp[1],dp[2]))