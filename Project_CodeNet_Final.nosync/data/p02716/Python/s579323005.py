import sys
input = sys.stdin.readline
N = int(input())
A = list(map(int,input().split()))
if N%2 == 0:
  dp = [[0]*2 for _ in range(N)] #0index
  dp[0][0] = A[0]
  dp[1][1] = A[1]
  for i in range(2,N):
    dp[i][0] = dp[i-2][0]+A[i]
    if i-3>=0:
      dp[i][1] = max(dp[i-2][1],dp[i-3][0])+A[i]
    else:
      dp[i][1] = max(dp[i-2][1],0)+A[i]
  ans = max(dp[-2][0],dp[-1][1])
  print(ans)
#i個目を使ってj(0-2)回多く飛んでいる。
else: #N%2 == 1:
  dp = [[0]*3 for _ in range(N)] #0index
  dp[0][0] = A[0]
  dp[1][1] = A[1]
  dp[2][2] = A[2]
  dp[2][0] = A[0]+A[2]
  #print(dp)
  for i in range(3,N):
    dp[i][0] = dp[i-2][0]+A[i]
    if i-3 >= 0:
      dp[i][1] = max(dp[i-2][1],dp[i-3][0])+A[i]
    else:
      dp[i][1] = max(dp[i-2][1],0)+A[i]
    if i-4 >= 0:
      dp[i][2] = max(dp[i-2][2],dp[i-3][1],dp[i-4][0])+A[i]
    elif i-3 >= 0:
      dp[i][2] = max(dp[i-2][2],dp[i-3][1],0)+A[i]
  #else:
  #  dp[i][2] = max(dp[i-2][2],0,0)+A[i]
  #print(dp[-1],dp[-2],dp[-3])

  ans = max(dp[-3][0],dp[-2][1],dp[-1][2])
  print(ans)
  exit()