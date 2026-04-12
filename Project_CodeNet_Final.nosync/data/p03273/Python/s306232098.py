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

h,w = LI()
a = [input() for _ in range(h)]
check_h = [True]*h
check_w = [True]*w
for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            break
    else:
        check_h[i] = False
for i in range(w):
    for j in range(h):
        if a[j][i] == '#':
            break
    else:
        check_w[i] = False

ans = []
for i in range(h):
    if check_h[i]:
        s = ''
        for j in range(w):
            if check_w[j]:
                s += a[i][j]
        ans.append(s)
for i in ans:
    print(i)