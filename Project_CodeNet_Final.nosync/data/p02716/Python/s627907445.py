import sys

# import bisect
# from collections import Counter, deque, defaultdict
# import copy
# from heapq import heappush, heappop, heapify
# import itertools
# from operator import attrgetter, itemgetter
# import math

# from numba import jit
# import numpy as np

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n = int(input())
    a = [0] + list(map(int, readline().split()))

    if n == 2:
        print(max(a[1],a[2]))
        sys.exit()

    dp = [[0] * 2 for _ in range(n + 1)]

    # 普通に選ぶ場合
    dp[1][0] = 0
    dp[2][0] = max(a[1], a[2])
    dp[3][0] = max(a[1], a[2], a[3])

    # 1個多く選ぶ場合（奇数個のみ）
    dp[1][1] = a[1]
    dp[3][1] = a[1] + a[3]

    i = 4

    while i < n + 1:
        cur1 = a[i]

        # 偶数だよ
        dp[i][0] = max(dp[i - 1][1], dp[i - 2][0] + cur1)

        if i == n:
            break

        i += 1
        cur2 = a[i]

        # 奇数だよ
        dp[i][0] = max(dp[i - 2][0] + cur2, dp[i - 3][0] + cur2, dp[i - 1][0], dp[i - 2][1])
        dp[i][1] = dp[i - 2][1] + cur2

        i += 1

    print(dp[n][0])


if __name__ == '__main__':
    main()
