import sys

read = sys.stdin.read
sys.setrecursionlimit(10 ** 7)


def solve():
    n, *a = map(int, read().split())
    a = tuple(a)
    dp = [[0] * n for _ in range(n)]
    for i in range(n):
        dp[i][i] = a[i]
    for i in range(n - 2, -1, -1):
        for j in range(i + 1, n):
            L = a[i] - dp[i + 1][j]
            R = a[j] - dp[i][j - 1]
            if L > R:
                dp[i][j] = L
            else:
                dp[i][j] = R
    return dp[0][n - 1]


print(solve())
