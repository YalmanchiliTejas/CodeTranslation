# input
N = int(input())
a = list(map(int, input().split()))

# dp[i][j]: a[i], a[j] の選択肢があるとき、その後に蓄積されるX-Yの最大値
dp = [[0] * N for i in range(N)]

for i in range(N - 1, -1, -1):
  for j in range(i, N):
    if i == j:
      dp[i][j] = a[i]
    else:
      dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1])

print(dp[0][N - 1])