from sys import stdin
import sys
import math
from functools import reduce
import functools
import itertools
from collections import deque,Counter,defaultdict
from operator import mul
import copy
# ! /usr/bin/env python
# -*- coding: utf-8 -*-
import heapq
sys.setrecursionlimit(10**6)
INF =  float("inf")
import bisect

N = int(input())
a = [0] + list(map(int, input().split()))

o = [a[2*i+1] for i in range(N//2)]
o = list(itertools.accumulate(o))

dp = [0 for i in range(N+1)]

dp[0] = dp[1] = 0
dp[2] = max(a[1], a[2])
if N > 2: dp[3] = max([a[1], a[2], a[3]])

if N > 3:
    for i in range(4, N+1):
        if i % 2 == 0:
            dp[i] = max(dp[i-2] + a[i], o[(i-3)//2] + a[i-1])
        else:
            dp[i] = max([dp[i-2] + a[i], dp[i-3] + a[i-1], o[(i-2)//2] ])

print(dp[N])


