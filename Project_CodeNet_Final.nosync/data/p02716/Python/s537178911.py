n=int(input())
arr=list(map(int,input().split()))
if n<=3:
  print(max(arr))
  exit()
lim=n%2+2
dp=[[0]*lim for _ in range(n+1)]
for i in range(n):
  dp[i+1][0]=dp[i-1][0]+arr[i]
  dp[i+1][1]=max(dp[i-1][1]+arr[i],dp[i-2][0]+arr[i])
  if lim==3:
    dp[i+1][2]=max(dp[i-1][2]+arr[i],dp[i-2][1]+arr[i],dp[i-3][0]+arr[i])
print(max(dp[-1][:lim]))