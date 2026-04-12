import re
import sys
import math
import itertools
import bisect
from copy import copy
from collections import deque,Counter
from decimal import Decimal
import functools
def v(): return input()
def k(): return int(input())
def S(): return input().split()
def I(): return map(int,input().split())
def X(): return list(input())
def L(): return list(input().split())
def l(): return list(map(int,input().split()))
def lcm(a,b): return a*b//math.gcd(a,b)
sys.setrecursionlimit(10 ** 9)
mod = 10**9+7
cnt = 100000
ans = 0
inf = float("inf")
al = "abcdefghijklmnopqrstuvwxyz"

n = k()
a = l()

ruiseki = list(itertools.accumulate(a))

for i in range(n-1):
    ans += a[i]*(ruiseki[-1]-ruiseki[i])

print(ans % mod)