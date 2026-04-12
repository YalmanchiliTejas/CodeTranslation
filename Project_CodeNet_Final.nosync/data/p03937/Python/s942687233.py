#!/usr/bin/env python3
#AGC7 A

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

h,w = LI()
m = [list(input()) for _ in range(h)]
cnt = 0
for i in range(h):
    for j in range(w):
        if m[i][j] == '#':
            cnt += 1
if cnt == h + w - 1:
    print('Possible')
else:
    print('Impossible')
