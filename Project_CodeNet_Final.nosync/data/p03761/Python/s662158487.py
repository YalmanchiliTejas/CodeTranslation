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

n = I()
s = [input() for _ in range(n)]
s = [Counter(i) for i in s]
ans = ''
for i in range(26):
    t = chr(ord('a') + i)
    cnt = inf
    for j in range(n):
        cnt = min(cnt,s[j][t])
    ans += t*cnt
print(ans)