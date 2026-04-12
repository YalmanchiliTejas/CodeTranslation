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

A, B, C, X, Y = list(map(int, sys.stdin.readline().split()))

# そのまま買う
a1 = A * X + B * Y
# AB だけ使う
a2 = C * max(X, Y) * 2
# 少ない方に AB を使う
a3 = C * min(X, Y) * 2
if X > Y:
    a3 += A * (X - Y)
else:
    a3 += B * (Y - X)

print(min(a1, a2, a3))

