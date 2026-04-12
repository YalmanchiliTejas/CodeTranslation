import sys
sys.setrecursionlimit(2147483647)
INF = float("inf")
MOD = 10**9 + 7 # 998244353
input = lambda:sys.stdin.readline().rstrip()
from functools import lru_cache
def resolve():
    n = int(input())
    A = list(map(int, input().split()))

    dp = [[None] * (n + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        dp[i][i] = 0

    for width in range(1, n + 1):
        for l in range(n):
            r = l + width
            if r > n:
                break
            turn = (n - (r - l)) & 1
            if turn & 1 == 0:
                dp[l][r] = max(A[l] + dp[l + 1][r], A[r - 1] + dp[l][r - 1])
            else:
                dp[l][r] = min(-A[l] + dp[l + 1][r], -A[r - 1] + dp[l][r - 1])


    print(dp[0][n])
resolve()