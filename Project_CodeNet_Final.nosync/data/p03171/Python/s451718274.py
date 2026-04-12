n = int(input())
a = list(map(int,input().split()))
dp = [[0] * (n+1) for i in range(n+1)]
dp[0][0] = 0
for j in range(1,n+1):
  for i in range(n+1-j):
    if (n-j) %2 == 0:
      dp[i][i+j] = max(dp[i+1][i+j] + a[i],dp[i][i+j-1]+a[i+j-1])
    else:
      dp[i][i+j] = min(dp[i+1][i+j] - a[i],dp[i][i+j-1]-a[i+j-1])
print(dp[0][n])