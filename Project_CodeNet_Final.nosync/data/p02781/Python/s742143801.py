# import bisect
from collections import Counter, deque
# import copy
# from heapq import heappush, heappop, heapify
# from fractions import gcd
# import itertools
# from operator import attrgetter, itemgetter
# import math

import sys

# import numpy as np

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n = input()
    p = int(input())
    l = len(n)

    n_0 = int(str(n)[0])

    dp = [[[0] * 2 for _ in range(p + 2)] for __ in range(l)]
    dp[0][0][0] = 0
    dp[0][0][1] = 1
    dp[0][1][0] = 1
    dp[0][1][1] = (n_0 - 1)

    for i in range(l - 1):
        a = int(n[i + 1])
        if a != 0:
            for j in range(p + 1):
                dp[i + 1][j + 1][0] += dp[i][j][0]
                dp[i + 1][j + 1][1] += 9 * dp[i][j][1] + (a - 1) * dp[i][j][0]
                dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1]
        else:
            for j in range(p + 1):
                dp[i + 1][j + 1][1] += 9 * dp[i][j][1]
                dp[i + 1][j][0] += dp[i][j][0]
                dp[i + 1][j][1] += dp[i][j][1]

    print(dp[l - 1][p][0] + dp[l - 1][p][1])


if __name__ == '__main__':
    main()
