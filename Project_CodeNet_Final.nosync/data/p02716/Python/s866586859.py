N=int(input())
A=list(map(int,input().split()))

if N<=3:
  print(max(A))
  exit(0)
  
INF = 10**(9+6)
if N % 2:
  # when N is odd, 2 blocks are skippable
  dp = [[-INF]*3 for i in range(N)]
  
  dp[0][0] = A[0]
  dp[1][1] = A[1]
  dp[2][2] = A[2]
  
  for i in range(N):
    if i+2 < N:
      for j in range(3):
        if dp[i+2][j] < dp[i][j] + A[i+2]:
          dp[i+2][j] = dp[i][j] + A[i+2]
    if i+3 < N:
      for j in range(2):
        if dp[i+3][j+1] < dp[i][j] + A[i+3]:
          dp[i+3][j+1] = dp[i][j] + A[i+3]
    if i+4 < N:
      if dp[i+4][2] < dp[i][0] + A[i+4]:
        dp[i+4][2] = dp[i][0] + A[i+4]
  print(max(dp[-3][0],dp[-2][1],dp[-1][2]))
  
else:
  # when N is even, 1 block is skippable
  dp = [[-INF]*2 for i in range(N)]
  
  dp[0][0] = A[0]
  dp[1][1] = A[1]
  
  for i in range(N):
    if i+2 < N:
      for j in range(2):
        if dp[i+2][j] < dp[i][j] + A[i+2]:
          dp[i+2][j] = dp[i][j] + A[i+2]
    if i+3 < N:
      if dp[i+3][1] < dp[i][0] + A[i+3]:
        dp[i+3][1] = dp[i][0] + A[i+3]
  print(max(dp[-2][0],dp[-1][1]))
