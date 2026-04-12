# @author 

import sys

class LDeque:
    def solve(self):
        n = int(input())
        a = [int(_) for _ in input().split()]
        dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            dp[i][i] = a[i]
            for j in range(i + 1, n):
                dp[i][j] = max(a[i] - dp[i + 1][j], -dp[i][j - 1] + a[j])

        print(dp[0][n - 1])

solver = LDeque()
input = sys.stdin.readline

solver.solve()
