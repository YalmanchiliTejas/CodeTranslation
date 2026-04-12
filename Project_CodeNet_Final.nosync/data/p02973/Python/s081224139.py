from bisect import bisect_right as right
import sys
readline = sys.stdin.buffer.readline

N = int(input())
A = [int(input()) for _ in range(N)][::-1]

INF = 10**10
dp = [INF] * (N+1)

answer = 0
for a in A:
  r = right(dp, a)
  if dp[r] > a:
    if dp[r] == INF:
      answer += 1
    dp[r] = a
print(answer)