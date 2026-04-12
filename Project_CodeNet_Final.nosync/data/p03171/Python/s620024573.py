n = int(input())
a = list(map(int,input().split()))
dp = [[0 for i in range(n+1)] for j in range(n+1)]
for i in range(1,n+1):
  dp[i][i] = a[i-1]
for w in range(1,n):
  for i in range(1,n-w+1):
    j = i+w
    dp[i][j] = max(a[i-1]-dp[i+1][j],a[j-1]-dp[i][j-1])
print(dp[1][n])