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
# INF =  float("inf")
INF = 10**18
import bisect
import statistics
mod = 10**9+7
# mod = 998244353

N = input()
K = int(input())

dp = [[[0]*(K+2) for j in range(2)] for i in range(len(N) + 1)]
dp[0][1][0] = 1

for i in range(len(N)):
    for k in range(K+1):
        dp[i+1][0][k] += dp[i][0][k]
        dp[i+1][0][k+1] += dp[i][0][k]*9

        if N[i] != "0":
            dp[i+1][0][k] += dp[i][1][k]
            dp[i+1][0][k+1] += dp[i][1][k]*(int(N[i])-1)
            dp[i+1][1][k+1] += dp[i][1][k]
        else:
            dp[i+1][1][k] += dp[i][1][k]

print(dp[-1][0][K] + dp[-1][1][K])