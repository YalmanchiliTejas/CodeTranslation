from collections import deque, Counter, defaultdict
from itertools import chain, combinations
import json
# import numpy as np
import bisect
import sys
import math
import bisect
from functools import lru_cache
import itertools

sys.setrecursionlimit(10 ** 8)

M = 10 ** 9 + 7
INF = 10 ** 17


def main():
    # N = int(input())
    N, X, M = [int(a) for a in input().split()]
    # D = [
    #     [int(a) for a in input().split()]
    #     for _ in range(N)
    # ]

    h = {X: 0}

    totals = [X]

    t = X

    c = X
    counter = 0
    while True:
        c = (c * c) % M
        if c in h:
            counter += 1
            t += c
            last_index = h[c]
            diff = t - totals[last_index]
            width = counter - last_index
            amari = last_index
            break
        counter += 1
        h[c] = counter
        t += c
        totals.append(t)

    if N <= amari:
        print(totals[N - 1])
        return

    N -= amari + 1
    rep = N // width
    mod = N % width

    k = totals[amari + mod]

    T = rep * diff + k
    print(T)


if __name__ == "__main__":
    main()
