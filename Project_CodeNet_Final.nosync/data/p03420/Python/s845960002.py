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
mod = 10**9 + 7
inf = float('inf')
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))

n, k = LI()
if k == 0:
    print(n ** 2)
    quit()
ans = 0
for b in range(1, n+1):
    x, y = divmod(n, b)
    z = b - k
    if z < 0:
        continue
    if y - k + 1 < 0:
        ans += z * x
    else:
        ans += z * x + (y - k + 1)
print(ans)