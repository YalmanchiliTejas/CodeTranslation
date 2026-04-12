# F - Knapsack for All Segments
# https://atcoder.jp/contests/abc159/tasks/abc159_f

MOD = 998244353

n, s = map(int, input().split())
A = list(map(int, input().split()))

# dp[i][j] = i 番目までの選択をして、1 つめの選択肢を選んだ k に対する ak の和が j であるような場合の数
dp = [[0] * (s + 1) for _ in range(n + 1)]

for i in range(n):
  dp[i + 1][0] = 1
  if A[i] <= s:
     dp[i + 1][A[i]] = 1
  for j in range(s + 1):
    dp[i + 1][j] += dp[i][j] 
    dp[i + 1][j] %= MOD
    if j + A[i] <= s:
      dp[i + 1][j + A[i]] += dp[i][j]
      dp[i + 1][j + A[i]] %= MOD

print(sum(i[-1] for i in dp) % MOD)