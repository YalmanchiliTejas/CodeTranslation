n = int(input())
a = [0]+list(map(int,input().split()))
dp = [[0]*(n+2) for _ in range(n+2)]
for l in range(1,n+2):
  for i in range(1,n-l+2):
    j = l+i
    if (n-l)%2 == 1:
      dp[i][j] = min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1])
    else:
      dp[i][j] = max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1])
print(dp[1][n+1])