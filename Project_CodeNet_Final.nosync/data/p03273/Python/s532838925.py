import bisect
import os
from collections import Counter, deque
from fractions import gcd
from functools import lru_cache
from functools import reduce
import functools
import heapq
import itertools
import math
import numpy as np
import re
import sys

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")

H, W = list(map(int, sys.stdin.readline().split()))
A = np.array([list(sys.stdin.readline().rstrip()) for _ in range(H)])

cols = np.array([c for c in A.T if np.any(c == '#')])
rows = np.array([r for r in cols.T if np.any(r == '#')])

for row in rows:
    print(''.join(row))
