# python3
# -*- coding: utf-8 -*-
import sys
import math
import bisect
from fractions import gcd
from itertools import count, permutations
from functools import lru_cache
from collections import deque, defaultdict
from pprint import pprint

INF = float('inf')

ii = lambda: int(input())
mis = lambda: map(int, input().split())
lmis = lambda: list(mis())
lmtx = lambda h: [list(map(int, lmis())) for _ in range(h)]
sys.setrecursionlimit(1000000000)


def lcm(a, b):
    return (a * b) // gcd(a, b)


# main
n = ii()
alist = lmis()

asum = sum(alist[1:n])

sum = 0
for i in range(n-1):
    sum += alist[i] * asum
    asum -= alist[i+1]

print(sum % 1000000007)
