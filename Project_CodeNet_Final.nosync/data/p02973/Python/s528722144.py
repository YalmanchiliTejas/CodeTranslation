#!/usr/bin/env python3

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

n = int(input())
a = [int(input()) for _ in range(n)]
dp = [float('inf')]*n
for i in range(n):
    x = bisect.bisect_right(dp,-a[i])
    dp[x] = -a[i]
c = dp.count(float('inf'))
print(n-c)
