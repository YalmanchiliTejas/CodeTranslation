import sys
readline = sys.stdin.readline

N = int(readline())
A = list(map(int,readline().split()))

dp = [[0] * (N + 1) for i in range(N + 1)]

# [i,j)
for l in range(1, N + 1):
  for i in range(N - l + 1):
    j = i + l
    
    if (N - l) % 2 == 0: # 先手
      dp[i][j] = max(dp[i + 1][j] + A[i], dp[i][j - 1] + A[j - 1])
    else:
      dp[i][j] = min(dp[i + 1][j] - A[i], dp[i][j - 1] - A[j - 1])
    
print(dp[0][N])