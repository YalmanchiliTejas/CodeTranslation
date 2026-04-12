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

n, x, m = LI()
check = [-1] * (m+1)
cnt = [-1] * (m+1)
ans = x
tmp = x
for i in range(min(n-1, m-1)):
    if check[tmp % m] < 0:
        check[tmp % m] = ans
        cnt[tmp % m] = i
        ans += tmp**2 % m
        tmp = tmp**2 % m
    else:
        roop = i - cnt[tmp % m]
        tmp2 = ans - check[tmp % m]
        r, l = (n-1 - i) // roop, (n-1 - i) % roop
        ans += tmp2 * r
        for j in range(l):
            ans += tmp**2 % m
            tmp = tmp**2 % m
        print(ans)
        break
else:
    print(ans)
         