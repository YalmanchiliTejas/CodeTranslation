N = int(input().strip())
A = list(map(int, input().strip().split()))

if N % 2 == 0:
  dp = [[0 for _ in range(N)] for _ in range(2)]
  dp[0][0] = A[0]
  dp[1][1] = A[1]
  for i in range(2, N):
    if i % 2 == 0:
      dp[0][i] = dp[0][i-2] + A[i]
    else:
      dp[1][i] = max(dp[1][i-2], dp[0][i-3]) + A[i]
  print(max(dp[-1][-1], dp[-2][-2]))
else:
  dp = [[0 for _ in range(N)] for _ in range(3)]
  dp[0][0] = A[0]
  dp[1][1] = A[1]
  dp[2][2] = A[2]
  for i in range(2, N):
    if i % 2 == 0:
      dp[0][i] = dp[0][i-2] + A[i]
      dp[2][i] = max(dp[0][i-4], dp[1][i-3], dp[2][i-2]) + A[i]
    else:
      dp[1][i] = max(dp[1][i-2], dp[0][i-3]) + A[i]
  print(max(dp[-1][-1], dp[-2][-2], dp[-3][-3]))
