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
import statistics
mod = 10**9+7

K = input()
D = int(input())

n = len(K)

dp = [[[0 for k in range(D)] for j in range(2)] for i in range(n+1)]
dp[0][0][0] = 1

for i in range(1,n+1):
    for k in range(D):
        for j in range(10):
            dp[i][1][k] = (dp[i][1][k] + dp[i-1][1][(k-j) % D]) % mod
        for j in range(int(K[i-1])):
            dp[i][1][k] = (dp[i][1][k] + dp[i-1][0][(k-j) % D]) % mod
        dp[i][0][k] = (dp[i][0][k] + dp[i-1][0][(k-int(K[i-1])) % D]) % mod

print((dp[n][1][0] + dp[n][0][0] -1) % mod)
