import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline #inputに置き換え可能

from bisect import bisect

# N: 数列の長さ
# A[i]: a_i の値
def solve(N, A):
    INF = 10**10

    dp = [INF]*(N+1)
    dp[0] = -1
    for a in A:
        idx = bisect(dp, a)
        dp[idx] = min(a, dp[idx])
    return max(i for i in range(N+1) if dp[i] < INF)

n = int(input())
a = [int(input()) for i in range(n)]
a.reverse()

print(solve(n, a))