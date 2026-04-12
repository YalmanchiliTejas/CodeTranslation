n = int(input())
a = list(map(int,input().split()))
dp = [[0]*(n+1) for j in range(n+1)]

## dp[j][i]:iは始点、jは列の長さを表す
for i in range(n):
  dp[0][i] = 0

for j in range(1,n+1):
  for i in range(n):
    if i+j <= n:
      dp[j][i] = max(a[i]-dp[j-1][i+1],a[i+j-1]-dp[j-1][i])
print(dp[n][0])