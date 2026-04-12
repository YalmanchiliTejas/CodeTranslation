import sys
import bisect

stdin = sys.stdin
 
ri = lambda: int(rs())
rl = lambda: list(map(int, stdin.readline().split()))
rs = lambda: stdin.readline().rstrip()  # ignore trailing spaces

N = ri()
INF = 10 ** 18
A = [10 ** 10 - ri() for _ in range(N)]
dp = [INF] * (N+1)
for a in A:
    i = bisect.bisect_right(dp, a)
    dp[i] = a

print(bisect.bisect_left(dp, INF))
#39 答え見る
