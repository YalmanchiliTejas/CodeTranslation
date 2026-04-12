#!/usr/bin/env python3
#ABC134 E

import sys
import math
import bisect
sys.setrecursionlimit(1000000000)
from heapq import heappush, heappop
from collections import defaultdict
from itertools import accumulate
from collections import Counter
from collections import deque
from operator import itemgetter
from itertools import permutations
mod = 10**9 + 7
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))

n = I()
a = [I() for _ in range(n)]

x = [float('inf') for _ in range(n)]
for i in range(n)[::-1]:
    r = bisect.bisect_right(x,a[i])
    x[r] = a[i]
cnt = x.count(float('inf'))
print(n-cnt)
