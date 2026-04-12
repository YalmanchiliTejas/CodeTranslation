import sys
input = sys.stdin.readline
N, S = map(int, input().split())
a = list(map(int, input().split()))
mod = 998244353

dp = [[0] * (S + 1) for _ in range(N + 1)]
dp[0][0] = 1
for i in range(N):
  dp[i][0] = i + 1
  for j in range(S + 1):
    if j + a[i] < S:
      dp[i + 1][j + a[i]] += dp[i][j]
      dp[i + 1][j + a[i]] %= mod
    elif j + a[i] == S:
      dp[i + 1][j + a[i]] += dp[i][j] * (N - i)
      dp[i + 1][j + a[i]] %= mod
    dp[i + 1][j] += dp[i][j]
    dp[i + 1][j] %= mod
print(dp[-1][-1])
