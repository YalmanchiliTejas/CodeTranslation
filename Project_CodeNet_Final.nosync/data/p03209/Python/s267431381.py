import sys

# import re
import math
import collections
# import decimal
import bisect
import itertools
import fractions
# import functools
import copy
import heapq
import decimal
# import statistics
import queue

sys.setrecursionlimit(10000001)
INF = 10 ** 16
MOD = 10 ** 9 + 7

ni = lambda: int(sys.stdin.readline())
ns = lambda: map(int, sys.stdin.readline().split())
na = lambda: list(map(int, sys.stdin.readline().split()))


# ===CODE===


def main():
    n, x = ns()
    lim = 51
    total = [int(0) for _ in range(lim)]
    P_total = [int(0) for _ in range(lim)]

    total[0] = 1
    for i in range(1, lim):
        total[i] = total[i - 1] * 2 + 3

    P_total[0] = 1
    for i in range(1, lim):
        P_total[i] = P_total[i - 1] * 2 + 1

    ans = 0
    base = 1
    L = n
    flg = True
    while base != x and L != 0:
        if base + total[L] // 2 <= x and flg:
            base += total[L] // 2
            ans += P_total[L - 1] + 1
            flg = False
        else:
            flg = True
            base += 1
            L -= 1
            if L == 0:
                ans += 1

    print(ans)


if __name__ == '__main__':
    main()
