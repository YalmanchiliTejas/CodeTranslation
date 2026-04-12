import math
n=int(input())
a=list(map(int, input().split()))
dp=[0]*n
dp[0]=0
dp[1]=max(a[0],a[1])
curr=a[0]
for i in range(2,n):
  if i&1==1:
    curr+=a[i-1]
    dp[i]=max(curr,dp[i-2]+a[i])
  else: dp[i]=max(dp[i-2]+a[i],dp[i-1])
print(dp[n-1])
