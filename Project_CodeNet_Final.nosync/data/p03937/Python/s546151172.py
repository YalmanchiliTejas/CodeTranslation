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

h, w = LI()
a = [list(input()) for _ in range(h)]
dx,dy = [1,0],[0,1]
flag = True
for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            que = deque()
            que.append((i,j))
            a[i][j] = '.'
            while que:
                y,x = que.popleft()
                for k in range(2):
                    ny, nx = y + dy[k], x + dx[k]
                    if 0 <= ny < h and 0 <= nx < w:
                        if a[ny][nx] == '#':
                            que.append((ny,nx))
                            a[ny][nx] = '.'
                            break
            flag = False
            break
    if not flag:
        break


for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            print('Impossible')
            quit()
print('Possible')