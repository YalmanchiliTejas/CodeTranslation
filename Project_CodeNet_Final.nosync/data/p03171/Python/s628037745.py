import sys
readline = sys.stdin.readline

N = int(readline())
A = list(map(int,readline().split()))

# dp[l][r] = [l:r)の区間から起こり得るX - Yの最大値
# [N - 区間の長さ] = 偶数のとき、次に取るのは先手

dp = [[0] * (N + 1) for i in range(N + 1)]

for k in range(1, N + 1): # 区間の長さ
  for i in range(N + 1 - k):
    if (N - k) % 2 == 0: # 先手番
      dp[i][i + k] = max(dp[i + 1][i + k] + A[i], dp[i][i + k - 1] + A[i + k - 1])
    else: # 後手番
      dp[i][i + k] = min(dp[i + 1][i + k] - A[i], dp[i][i + k - 1] - A[i + k - 1])

print(dp[0][N])