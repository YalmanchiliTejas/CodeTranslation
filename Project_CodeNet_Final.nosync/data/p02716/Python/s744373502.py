#!/usr/bin/env python3

import sys
import math
from bisect import bisect_right as br
from bisect import bisect_left as bl
sys.setrecursionlimit(2147483647)
from heapq import heappush, heappop,heappushpop
from collections import defaultdict
from itertools import accumulate
from collections import Counter
from collections import deque
from operator import itemgetter
from itertools import permutations
mod = 10**9+7
inf = float('inf')
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))

n = I()
a = LI()
if n == 3:
    print(max(a))
    quit()
dp1 = [-inf]*(n+1) 
dp2 = [-inf]*(n+1)
dp3 = [-inf]*(n+1)
dp1[0] = 0
dp2[0] = 0
dp3[0] = 0
dp1[1] = a[0]
dp2[2] = a[1]
for i in range(3,n+1):
    dp1[i] = dp1[i-2] + a[i-1]
    dp2[i] = max(dp2[i-2],dp1[i-3]) + a[i-1]
    dp3[i] = max(dp3[i-2],dp2[i-3],dp1[i-4]) + a[i-1]
if n % 2:
    print(max(dp1[n-2], dp2[n], dp3[n]))
else:
    print(max(dp1[n-1], dp2[n]))

