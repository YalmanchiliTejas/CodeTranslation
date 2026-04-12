import bisect
import sys

input = sys.stdin.readline

ri = lambda: int(input())
rs = lambda: input().rstrip()
ril = lambda: list(map(int, input().split()))
rsl = lambda: input().rstrip().split()
ris = lambda n: [ri() for _ in range(n)]
rss = lambda n: [rs() for _ in range(n)]
rils = lambda n: [ril() for _ in range(n)]
rsls = lambda n: [rsl() for _ in range(n)]

n = ri()
ls = ris(n)
ls = [-x for x in ls]

dp = [float('inf')] * n
for x in ls:
    dp[bisect.bisect_right(dp, x)] = x
print(bisect.bisect_left(dp, float('inf')))