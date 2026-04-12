import bisect
from collections import Counter, deque
from fractions import gcd
from functools import lru_cache
from functools import reduce
import functools
import heapq
import itertools
import math
from operator import mul

import numpy as np
import re
import sys

sys.setrecursionlimit(10000)
INF = float('inf')

N, K = list(map(int, input().split()))

ans = 0
if K == 0:
    print(N ** 2)
    exit()
# K < b <= N
for b in range(K + 1, N + 1):
    nk = (N - K)
    bk = (b - K)
    ans += nk // b * bk + min((nk % b) + 1, bk)
print(ans)
