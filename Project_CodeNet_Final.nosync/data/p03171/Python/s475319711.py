N = int(input())
A = list(map(int, input().split()))
dp = [[float('inf')]*N for _ in range(N)]
for i in range(N):
  if (N-1)%2==0:
    dp[i][i] = A[i]
  else:
    dp[i][i] = -A[i]
for k in range(1,N):
  for i in range(N):
    j = i+k
    if j>N-1:
      break
    if (N-(k+1))%2==0:
      dp[i][j] = max(dp[i][j-1]+A[j],dp[i+1][j]+A[i])
    else:
      dp[i][j] = min(dp[i][j-1]-A[j],dp[i+1][j]-A[i])
ans = dp[0][N-1]
print(ans)