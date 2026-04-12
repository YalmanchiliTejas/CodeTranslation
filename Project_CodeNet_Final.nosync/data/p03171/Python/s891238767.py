# coding: utf-8

import sys
input = sys.stdin.readline

def f(n, a):
    dp = [[0] * n for _ in range(n)]
    # dp[i][i] を a[i] で初期化
    for i in range(n):
        dp[i][i] = a[i]
    for i in range(n - 2, -1, -1):
        dpi = dp[i]
        dpi1 = dp[i + 1]
        for j in range(i + 1, n):
            r = a[i] - dpi1[j]
            l = a[j] - dpi[j - 1]
            dp[i][j] = r if r > l else l
            # dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1])
    return(dp[0][-1])

n = int(input()) # 1 <= n <= 3000
a = list(map(int, input().split()))
print(f(n, a))
