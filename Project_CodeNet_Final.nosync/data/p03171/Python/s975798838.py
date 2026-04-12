#!/usr/bin/env python3
#EDPC L

import sys
import math
from bisect import bisect_right as br
from bisect import bisect_left as bl
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
a = LI()
dp = [[0]*(n+1) for _ in range(n+1)]
for l in range(n)[::-1]:
    for r in range(l+1,n+1):
        if (n - (r-l)) % 2 == 0:
            dp[l][r] = max(dp[l+1][r] + a[l],dp[l][r-1] + a[r-1])
        else:
            dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1])
print(dp[0][-1])