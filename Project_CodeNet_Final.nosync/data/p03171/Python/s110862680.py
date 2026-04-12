import sys
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
inf = 10 ** 14
dp = [[0] * (N + 1) for _ in range(N)]
for l in range(N):
  for r in range(l, N + 1):
    if l == r: continue
    if (N - (r - l)) % 2: dp[l][r] = inf
    else: dp[l][r] = -inf
for c in range(N + 1):
  for l in range(N - c + 1):
    if l == N: continue
    r = l + c
    t = (N - (r - l)) % 2
    if l - 1 >= 0:
      if t == 0:
        dp[l - 1][r] = min(dp[l - 1][r], dp[l][r] - a[l - 1])
      else:
        dp[l - 1][r] = max(dp[l - 1][r], dp[l][r] + a[l - 1])
    if r + 1 <= N:
      if t == 0:
        dp[l][r + 1] = min(dp[l][r + 1], dp[l][r] - a[r])
      else:
        dp[l][r + 1] = max(dp[l][r + 1], dp[l][r] + a[r])
print(dp[0][N])