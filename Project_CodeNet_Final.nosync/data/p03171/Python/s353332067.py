from sys import stdin
import sys
import math
from functools import reduce
import functools
import itertools
from collections import deque,Counter
from operator import mul
import copy
# ! /usr/bin/env python
# -*- coding: utf-8 -*-
import heapq
sys.setrecursionlimit(10**6)

N = int(input())
a = [0] + list(map(int, input().split()))

dp = [[0]*(N+5) for i in range(N+5)]

for k in range(1,N+1):
    for l in range(1,N+2-k):
        r = l + k
        if (N-k) % 2 == 0:
            dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1])
        else:
            dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r - 1])

print(dp[1][N+1])