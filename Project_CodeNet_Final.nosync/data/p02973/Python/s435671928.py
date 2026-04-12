import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N,*A = map(int,read().split())

def LIS(seq,wider_sense = False):
    from bisect import bisect_left, bisect_right
    f = bisect_right if wider_sense else bisect_left
    N = len(seq)
    INF = 10**18
    dp = [INF] * (N+1)
    for x in seq:
        i = f(dp,x)
        dp[i] = x
    return f(dp,INF-1)

answer = LIS([-x for x in A],wider_sense=True)
print(answer)