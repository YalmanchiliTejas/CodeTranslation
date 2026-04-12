import sys
import bisect

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N = ir()
INF = 10 ** 10
dp = [INF] * N
# マイナスの値にしてLongest Increasing Sequence
for _ in range(N):
    a = 10 ** 9 - ir()
    i = bisect.bisect_right(dp, a)
    dp[i] = a

index = bisect.bisect_left(dp, INF)
print(index)
# 04