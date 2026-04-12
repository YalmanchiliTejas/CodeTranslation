from collections import deque, Counter, defaultdict
from itertools import chain, combinations
import json
# import numpy as np
import bisect
import sys
import math
import bisect
from functools import lru_cache

sys.setrecursionlimit(10 ** 8)

M = 10 ** 9 + 7
INF = 10 ** 17


def main():
    N = int(input())
    A = [int(a) for a in input().split()]

    @lru_cache(None)
    def f(i, j):
        if i < 0 or j < 0:
            return -INF
        if i == 0:
            return -INF
        if abs(j - i // 2 - 1) >= 2:
            return -INF
        if j == 0:
            return 0
        if j == 1:
            return max(A[:i])
        return max(A[i - 1] + f(i - 2, j - 1), f(i - 1, j))

    print(f(N, math.floor(N / 2)))


if __name__ == "__main__":
    main()

    