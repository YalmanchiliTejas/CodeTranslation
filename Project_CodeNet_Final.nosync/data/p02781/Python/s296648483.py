import sys
input = sys.stdin.readline
N = list(map(int, list(input())[: -1]))
K = int(input())
dp = [[0] * (K + 1) for _ in range(len(N) + 1)]
dplim = [[0] * (K + 1) for _ in range(len(N) + 1)]
dplim[0][0] = 1
for i in range(len(N)):
  for j in range(K + 1):
    if N[i] > 0 and (j < K): dplim[i + 1][j + 1] += dplim[i][j]
    else: dplim[i + 1][j] += dplim[i][j]
    for k in range(10):
      if k < N[i] and (j < K):
        dp[i + 1][j + (k > 0)] += dplim[i][j]
      if k > 0 and (j < K): dp[i + 1][j + 1] += dp[i][j]
      elif j < K: dp[i + 1][j] += dp[i][j]
res = 0
#print(dp, dplim)
for i in range(len(N) + 1):
  res += dp[i][-1]
print(res + dplim[-1][-1])