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

n = input()
m = len(n)
K = I()

dp1 = [[0]*4 for _ in range(m+1)] #等しい
dp2 = [[0]*4 for _ in range(m+1)] #未満
dp1[0][0] = 1
for i in range(m):
    x = int(n[i])
    for j in range(10):
        if j == x:
            if j == 0:
                for k in range(4):
                    dp1[i+1][k] += dp1[i][k]
                    dp2[i+1][k] += dp2[i][k]
            else:
                for k in range(3):
                    dp1[i+1][k+1] += dp1[i][k]
                    dp2[i+1][k+1] += dp2[i][k]
        elif j < x:
            if j == 0:
                for k in range(4):
                    dp2[i+1][k] += dp1[i][k]
                    dp2[i+1][k] += dp2[i][k]
            else:
                for k in range(3):
                    dp2[i+1][k+1] += dp1[i][k]
                    dp2[i+1][k+1] += dp2[i][k]
        else:
            for k in range(3):
                dp2[i+1][k+1] += dp2[i][k]
ans = dp1[m][K] + dp2[m][K]
print(ans)