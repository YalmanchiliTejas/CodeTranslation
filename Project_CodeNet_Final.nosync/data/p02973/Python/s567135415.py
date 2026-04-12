import bisect
import sys
input = sys.stdin.readline
N = int(input())
A = [int(input()) for _ in range(N)]

dp = [float('inf')]*(N+1)
for a in A[::-1]:
  idx = bisect.bisect_right(dp, a)
  dp[idx] = a

ans = 0
for n in dp:
  if n != float('inf'):
    ans += 1
print(ans)