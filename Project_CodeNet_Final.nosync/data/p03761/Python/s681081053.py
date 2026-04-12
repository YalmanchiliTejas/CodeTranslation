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

N = int(sys.stdin.readline())
S = [sys.stdin.readline().rstrip() for _ in range(N)]


def count(s):
    ret = defaultdict(int)
    for c in s:
        ret[c] += 1
    return ret


counts = count(S[0])
for s in S[1:]:
    cnts = count(s)
    for c, v in counts.items():
        counts[c] = min(counts[c], cnts[c])

s = []
for c, v in counts.items():
    if v:
        s.extend([c] * v)
s.sort()

print(''.join(s))
