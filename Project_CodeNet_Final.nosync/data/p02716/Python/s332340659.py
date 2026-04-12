n=int(input())
a=list(map(int,input().split()))
if n%2==0:
  dp=[[0 for i in range(2)] for j in range(n)]
  dp[0][0]=a[0]
  dp[1][1]=a[1]
  for i in range(2,n):
    if i==2:
      dp[i][0]=dp[i-2][0]+a[i]
      dp[i][1]=dp[i-2][1]+a[i]
    else:
      dp[i][0]=dp[i-2][0]+a[i]
      dp[i][1]=max(dp[i-2][1],dp[i-3][0])+a[i]
  print(max(dp[n-1][1],dp[n-2][0]))

else:
  dp=[[0 for i in range(3)] for j in range(n)]
  dp[0][0]=a[0]
  dp[1][1]=a[1]
  dp[2][2]=a[2]
  for i in range(2,n):
    if i==2:
      dp[i][0]=dp[i-2][0]+a[i]
      dp[i][1]=dp[i-2][1]+a[i]
    else:
      dp[i][0]=dp[i-2][0]+a[i]
      dp[i][1]=max(dp[i-2][1],dp[i-3][0])+a[i]
      dp[i][2]=max(dp[i-2][2],dp[i-3][1],dp[i-4][0])+a[i]
  print(max(dp[n-1][2],dp[n-2][1],dp[n-3][0]))