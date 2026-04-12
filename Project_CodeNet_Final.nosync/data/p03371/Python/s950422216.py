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

a,b,c,x,y = LI()
ans = 0
if a + b < 2*c:
    ans += (a + b)*min(x, y)
    if x > y:
        ans += (x-y)*a
    else:
        ans += (y-x)*b
else:
    ans += 2*c*min(x,y)
    if x > y:
        ans += (x-y)*min(a,2*c)
    else:
        ans += (y-x)*min(b,2*c)
print(ans)