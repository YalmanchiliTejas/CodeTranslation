n=int(input())
arr=list(map(int,input().split()))
if n%2==0:
  ans=-10**18
  dp=[[0]*2 for _ in range(n+10)]
  for i in range(n):
    dp[i+1][0]=dp[i-1][0]+arr[i]
    dp[i+1][1]=max(dp[i-1][1]+arr[i],dp[i-2][0]+arr[i])
  ans=max(ans,dp[n-1][0],dp[n][1])
  dp=[[0]*2 for _ in range(n+10)]
  for i in range(1,n):
    dp[i+1][0]=dp[i-1][0]+arr[i]
    dp[i+1][1]=max(dp[i-1][1]+arr[i],dp[i-2][0]+arr[i])
  ans=max(ans,dp[n][0])
  print(ans)
else:
  ans=-10**18
  dp=[[0]*3 for _ in range(n+10)]
  for i in range(n):
    dp[i+1][0]=dp[i-1][0]+arr[i]
    dp[i+1][1]=max(dp[i-1][1]+arr[i],dp[i-2][0]+arr[i])
    dp[i+1][2]=max(dp[i-1][2]+arr[i],dp[i-2][1]+arr[i],dp[i-3][0]+arr[i])
  ans=max(ans,dp[n-2][0],dp[n-1][1],dp[n][2])
  dp=[[0]*3 for _ in range(n+10)]
  for i in range(1,n):
    dp[i+1][0]=dp[i-1][0]+arr[i]
    dp[i+1][1]=max(dp[i-1][1]+arr[i],dp[i-2][0]+arr[i])
    dp[i+1][2]=max(dp[i-1][2]+arr[i],dp[i-2][1]+arr[i],dp[i-3][0]+arr[i])
  ans=max(ans,dp[n-1][0],dp[n][1])
  dp=[[0]*3 for _ in range(n+10)]
  for i in range(2,n):
    dp[i+1][0]=dp[i-1][0]+arr[i]
    dp[i+1][1]=max(dp[i-1][1]+arr[i],dp[i-2][0]+arr[i])
    dp[i+1][2]=max(dp[i-1][2]+arr[i],dp[i-2][1]+arr[i],dp[i-3][0]+arr[i])
  ans=max(ans,dp[n][0])
  print(ans)