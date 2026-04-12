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


N = int(sys.stdin.buffer.readline())
H = list(map(int, sys.stdin.buffer.readline().split()))

cummax = list(itertools.accumulate(H, max))
H = np.array(H, dtype=int)
cummax = np.array(cummax, dtype=int)
ans = np.count_nonzero(H >= cummax)
print(ans)
