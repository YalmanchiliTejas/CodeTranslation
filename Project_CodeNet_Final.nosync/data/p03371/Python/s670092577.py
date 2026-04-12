from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque, OrderedDict
from copy import deepcopy
from fractions import gcd
from functools import lru_cache, reduce
from math import ceil, floor
from sys import setrecursionlimit

import heapq
import itertools
import operator


inf = float('inf')


# globals
A, B, C, X, Y = 0, 0, 0, 0, 0


def set_inputs():
    global A, B, C, X, Y
    A, B, C, X, Y = get_li()
    return


def main():
    setrecursionlimit(100000)
    set_inputs()
    # ----------MAIN----------
    if 2 * C <= A + B:
        a = min(A, 2 * C)
        b = min(B, 2 * C)
        print(min(X, Y) * 2 * C + max(0, X - min(X, Y)) * a + max(0, Y - min(X, Y)) * b)
    else:
        print(A * X + B * Y)
    return
    # dp = [[0 for _ in range(Y + 1)] for _ in range(X + 1)]
    # for i in range(1, X + 1):
    #     dp[i][0] = dp[i-1][0] + A
    # for j in range(1, Y + 1):
    #     dp[0][j] = dp[0][j-1] + B
    # for i in range(1, X + 1):
    #     for j in range(1, Y + 1):
    #         dp[i][j] = min(
    #             dp[i-1][j] + A,
    #             dp[i][j-1] + B,
    #             dp[i-1][j-1] + C * 2)
    # print(dp[X][Y])
    # return


def get_int():
    return int(input())


def get_float():
    return float(input())


def get_str():
    return input().strip()


def get_li():
    return [int(i) for i in input().split()]


def get_lf():
    return [float(f) for f in input().split()]


def get_lc():
    return list(input().strip())


def get_data(n, types):
    if len(types) == 1:
        return [types[0](input()) for _ in range(n)]
    return zip(*(
        [t(x) for t, x in zip(types, input().split())]
        for _ in range(n)
    ))


if __name__ == '__main__':
    main()
