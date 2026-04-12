N=int(input())
a=[int(i) for i in input().split()]
dp=[[0]*(N+1) for i in range(N+1)]
for d in range(1,N+1):
  for i in range(N+1-d):
    if (N-d)%2==0:
      dp[i][i+d]=max(dp[i+1][i+d]+a[i],dp[i][i+d-1]+a[i+d-1])
    if (N-d)%2==1:
      dp[i][i+d]=min(dp[i+1][i+d],dp[i][i+d-1])
print(2*dp[0][N]-sum(a))
    