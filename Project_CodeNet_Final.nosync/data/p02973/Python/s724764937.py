#!/usr/bin/env python3
#ABC134 E
 
import sys
import math
import bisect
from heapq import heappush, heappop
from collections import defaultdict
from itertools import accumulate
from collections import Counter
from collections import deque
from operator import itemgetter
mod = 10**9 + 7
 
n = int(input())
a = [int(input()) for _ in range(n)]
m = []
for i in range(n):
    r = bisect.bisect_right(m,-a[i])
    if r == len(m):
        m.append(-a[i])
    else:
        m[r] = -a[i]
print(len(m))
