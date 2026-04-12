import sys
import re
import math
import collections
import decimal
import bisect
import itertools
import fractions
import functools
import copy
import heapq
import decimal
import statistics
import queue

# import numpy as np

sys.setrecursionlimit(10 ** 9)
INF = 10 ** 16
MOD = 10 ** 9 + 7
# MOD = 998244353

ni = lambda: int(sys.stdin.readline())
ns = lambda: map(int, sys.stdin.readline().split())
na = lambda: list(map(int, sys.stdin.readline().split()))


# ===CODE===

def main():
    n = ni()
    a = na()

    dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

    for d in range(1, n + 1):
        for l in range(n - d + 1):
            r = l + d

            # second
            if (n - d) % 2:
                dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r - 1])

            # first
            else:
                dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r - 1])

    print(dp[0][n])


if __name__ == '__main__':
    main()
