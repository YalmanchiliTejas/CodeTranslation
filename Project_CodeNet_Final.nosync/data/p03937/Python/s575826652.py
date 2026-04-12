import bisect
import heapq
import itertools
import math
import operator
import os
import re
import string
import sys
from collections import Counter, deque, defaultdict
from copy import deepcopy
from decimal import Decimal
from fractions import gcd
from functools import lru_cache, reduce
from operator import itemgetter, mul, add, xor

import numpy as np

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7

H, W = list(map(int, sys.stdin.readline().split()))
A = [list(sys.stdin.readline().rstrip()) for _ in range(H)]


def ok(h, w):
    return 0 <= h < H and 0 <= w < W


def dfs(h, w):
    A[h][w] = '.'
    dh = [0, 1, 0, -1]
    dw = [1, 0, -1, 0]
    cnt = 0
    for i, j in zip(dh, dw):
        cnt += ok(h + i, w + j) and A[h + i][w + j] == '#'
    if cnt == 1:
        for i, j in zip(dh, dw):
            if ok(h + i, w + j) and A[h + i][w + j] == '#' and i >= 0 and j >= 0:
                return dfs(h + i, w + j)
    return cnt == 0 and h == H - 1 and w == W - 1


if dfs(0, 0):
    print('Possible')
else:
    print('Impossible')
