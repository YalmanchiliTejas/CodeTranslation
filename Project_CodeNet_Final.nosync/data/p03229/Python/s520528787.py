#!/usr/bin/env python3
#Tenka1 C

import sys
import math
import bisect
sys.setrecursionlimit(1000000000)
from heapq import heappush, heappop,heappushpop
from collections import defaultdict
from itertools import accumulate
from collections import Counter
from collections import deque
from operator import itemgetter
from itertools import permutations
mod = 10**9 + 7
inf = float('inf')
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))

n = I()
a = [I() for _ in range(n)]
a.sort()
if n % 2:
    lower = a[:n//2]
    upper = a[n//2+1:]
    mid = a[n//2]
    x = 2*sum(upper) - 2*sum(lower) - mid + lower[-1]
    y = 2*sum(upper) - 2*sum(lower) + mid - upper[0]
    print(max(x,y))
else:
    lower = a[:n//2]
    upper = a[n//2:]
    x = 2*sum(upper) - upper[0]
    y = 2*sum(lower) - lower[-1]
    print(x-y)
