from bisect import bisect_right as br
INF = 10 ** 10
n = int(input())
alst = [int(input()) for _ in range(n)][::-1]
dp = [INF] * (n + 1)
dp[0] = -1
ans = 0
for a in alst:
  ind = br(dp, a)
  dp[ind] = a
  ans = max(ans, ind)
print(ans)