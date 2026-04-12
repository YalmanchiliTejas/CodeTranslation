import bisect
import heapq
import itertools
import math
import os
import re
import string
import sys
from collections import Counter, deque, defaultdict
from copy import deepcopy
from decimal import Decimal
from fractions import gcd
from functools import lru_cache, reduce
from operator import itemgetter

import numpy as np

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7

N, M = list(map(int, sys.stdin.readline().split()))
A, B = list(zip(*[map(int, sys.stdin.readline().split()) for _ in range(M)]))

graph = np.zeros((N, N), dtype=bool)
for a, b in zip(A, B):
    graph[a - 1][b - 1] = True
    graph[b - 1][a - 1] = True

cnt = 0
for order in itertools.permutations(range(1, N)):
    ok = graph[0][order[0]]
    for v, u in zip(order[:-1], order[1:]):
        ok &= graph[v][u]
    cnt += ok
print(cnt)
