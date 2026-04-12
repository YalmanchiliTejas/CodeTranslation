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
    n, k = ns()

    lim = 10 ** 5

    ans = 0
    for i in range(max(1, k + 1), n + 1):
        tmp1 = (i - k) * (n // i)
        tmp2 = max(n % i - max(k - 1, 0), 0) if n % i else 0
        ans += tmp1 + tmp2
        # print(i, tmp1, tmp2, ans)
    print(ans)


if __name__ == '__main__':
    main()
