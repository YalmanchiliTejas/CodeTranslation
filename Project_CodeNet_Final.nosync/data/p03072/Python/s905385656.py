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


# globals
inf = float('inf')
N = 0


def set_inputs():
    global N
    return


def main():
    setrecursionlimit(100000)
    set_inputs()
    # ----------MAIN----------
    n = get_int()
    h = get_li()
    highest = 0
    ans = 0
    for hi in h:
        if hi >= highest:
            ans += 1
            highest = hi
    print(ans)
    return


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


def get_data(n, types, sep=None):
    if len(types) == 1:
        return [types[0](input()) for _ in range(n)]
    return list(zip(*(
        [t(x) for t, x in zip(types, input().split(sep=sep))]
        for _ in range(n)
    )))


if __name__ == '__main__':
    main()
