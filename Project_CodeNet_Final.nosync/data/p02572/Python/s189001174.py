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

P = 10**9 + 7
k = 3
inv_t = [0]+[1]
for i in range(2,k):
  inv_t += [inv_t[P % i] * (P - int(P / i)) % P]

N = int(input())
A = list(map(int, input().split()))
AA = [A[i]**2 % mod for i in range(N)]

ans = 0
b = 0
for i in range(N):
    ans = (ans + A[i]) % mod
    b = (b + AA[i]) % mod
ans = ans % mod
b = b % mod

ans = (ans**2) % mod
ans = (ans - b) % mod

ans = (ans*inv_t[2]) % mod
print(ans)