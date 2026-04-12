import bisect
import cmath
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

sys.setrecursionlimit(10 ** 9)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7
# MOD = 998244353

H, W = list(map(int, sys.stdin.buffer.readline().split()))
S = [list(sys.stdin.buffer.readline().decode().rstrip()) for _ in range(H)]

S = np.array(S, dtype='U1')
ans = []
for s in S:
    if '#' in s:
        ans.append(s)
S = np.array(ans, dtype='U1')
ans = []
for s in S.T:
    if '#' in s:
        ans.append(s)
ans = np.array(ans, dtype='U1').T
for r in ans:
    print(''.join(r))
