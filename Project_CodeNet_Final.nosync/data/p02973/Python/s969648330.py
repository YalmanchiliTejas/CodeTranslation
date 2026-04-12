import sys
input = sys.stdin.buffer.readline
from bisect import bisect_right
N = int(input())
li_a = []
for _ in range(N):
    a = int(input())
    li_a.append(a)
INF = 10**15
dp = [INF]* N
for i in range(N-1, -1, -1):
    a = li_a[i]
    k = bisect_right(dp, a)
    dp[k] = a
check = INF-1
print(bisect_right(dp, check))