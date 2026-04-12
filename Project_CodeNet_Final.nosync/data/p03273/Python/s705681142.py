# region header
import sys
import math
from bisect import bisect_left, bisect_right, insort_left, insort_right
from collections import defaultdict, deque, Counter
from copy import deepcopy
from fractions import gcd
from functools import lru_cache, reduce
from heapq import heappop, heappush
from itertools import accumulate, groupby, product, permutations, combinations, combinations_with_replacement
from math import ceil, floor, factorial, log, sqrt, sin, cos
from operator import itemgetter
sys.setrecursionlimit(10**7)
rs = lambda: sys.stdin.readline().rstrip()
ri = lambda: int(rs())
rf = lambda: float(rs())
rs_ = lambda: [_ for _ in rs().split()]
ri_ = lambda: [int(_) for _ in rs().split()]
rf_ = lambda: [float(_) for _ in rs().split()]
INF = float('inf')
MOD = 10 ** 9 + 7
PI = math.pi
# endregion
H, W = ri_()
a = [[i for i in rs()] for _ in range(H)]
a = [i for i in a if i.count('#') > 0]
a = list(zip(*a))
a = [i for i in a if i.count('#') > 0]
a = list(zip(*a))
a = [''.join(i) for i in a]
for ai in a:
    print(ai)