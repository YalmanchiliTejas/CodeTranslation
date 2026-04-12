import sys
from bisect import bisect_left, bisect_right

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

# dp と bisect.insort
N = ir()
INF = 10 ** 12
dp = [INF] * (N+1)
for _ in range(N):
    a = ir()
    i = bisect_right(dp, -a)
    dp[i] = -a

print(bisect_left(dp, INF))
# 18