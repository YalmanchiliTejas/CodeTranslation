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
mod = 998244353
inf = float('inf')
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))

#参考:https://maspypy.com/atcoder-%E5%8F%82%E5%8A%A0%E6%84%9F%E6%83%B3-2019-03-22abc-159

n,s = LI()
a = LI()
ans = 0
dp = [[0]*(s+1) for _ in range(n)]
dp[0][0] = 1
if s >= a[0]:
    dp[0][a[0]] = 1
for i in range(1,n):
    b = a[i]
    for j in range(s+1):
        if j == 0:
            dp[i][j] = dp[i-1][j] + 1
        else:
            dp[i][j] = dp[i-1][j]
    for j in range(s+1):
        if dp[i-1][j]:
            if j + b <= s:
                if j == 0:
                    dp[i][j+b] += dp[i][j]
                    dp[i][j+b] %= mod
                else:
                    dp[i][j+b] += dp[i-1][j]
                    dp[i][j+b] %= mod
for i in dp:
    ans += i[-1]
    ans %= mod
print(ans)


