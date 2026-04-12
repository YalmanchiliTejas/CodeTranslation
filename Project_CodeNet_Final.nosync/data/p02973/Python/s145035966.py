import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

from bisect import bisect_right

N,*A = map(int,read().split())

def LIS(seq):
    # 狭義
    N = len(seq)
    INF = 10**18
    dp = [INF] * (N+1)
    for x in seq:
        i = bisect_right(dp,x)
        dp[i] = x
    return bisect_right(dp,INF-1)

answer = LIS([-x for x in A])
print(answer)