import sys
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
inf = 10 ** 16
if N % 2:
  dp = [[-inf] * 3 for _ in range(N + 2)]
  dp[0][0] = 0
  dp[1][1] = 0
  dp[2][2] = 0
  if N > 4: dp[4][2] = a[0]
  for i in range(N):
    for j in range(3):
      if dp[i][j] == -inf: continue
      if i + 2 <= N + 1: dp[i + 2][j] = max(dp[i + 2][j], dp[i][j] + a[i])
      if i + 3 <= N + 1 and (j < 2): dp[i + 3][j + 1] = max(dp[i + 3][j + 1], dp[i][j] + a[i])
      if i + 4 <= N + 1 and (j == 0): dp[i + 4][j + 1] = max(dp[i + 4][j + 1], dp[i][j] + a[i])
  print(max(dp[-1][-1], dp[-2][-2], dp[-3][-3]))
  #print(dp)
else:
  dp = [[-inf] * 2 for _ in range(N + 2)]
  dp[0][0] = 0
  dp[1][1] = 0
  for i in range(N):
    for j in range(2):
      if dp[i][j] == -inf: continue
      if i + 2 <= N + 1: dp[i + 2][j] = max(dp[i + 2][j], dp[i][j] + a[i])
      if i + 3 <= N + 1 and (j < 1): dp[i + 3][j + 1] = max(dp[i + 3][j + 1], dp[i][j] + a[i])
  print(max(dp[-1][-1], dp[-2][-2]))
  #print(dp)