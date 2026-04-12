import sys

import bisect

# from collections import Counter, deque

# import copy
# from heapq import heappush, heappop, heapify
# from fractions import gcd
# import itertools
# from operator import attrgetter, itemgetter
# import math


# import numpy as np

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n = int(input())
    a = [-int(readline()) for _ in range(n)]

    c = [1] * n

    for number in a:
        idx = bisect.bisect_right(c, number)
        c[idx] = number

    ans = bisect.bisect_left(c, 1)
    print(ans)


if __name__ == '__main__':
    main()
