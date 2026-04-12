N = int(input())
A = list(map(int,input().split()))
dp = [{} for _ in range(N+1)]
INF = -float('inf')
for i in range(1,N+1):
    mid = i//2
    dp[i][mid-2],dp[i][mid-1],dp[i][mid],dp[i][mid+1],dp[i][mid+2]=INF,INF,INF,INF,INF
dp[1][1] = A[0]
dp[2][1] = max(A[1],dp[1][1])
dp[1][0],dp[2][0]=0,0

for i in range(2,N):
  a = A[i]
  ma = (i+2)//2
  mi = i//2
  dp[i+1][ma] = max(dp[i][ma],dp[i-1][ma-1]+a)
  dp[i+1][mi] = max(dp[i][mi],dp[i-1][mi-1]+a)

print(dp[-1][N//2])