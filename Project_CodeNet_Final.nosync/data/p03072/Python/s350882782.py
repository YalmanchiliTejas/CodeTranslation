#!/usr/bin/env python

from collections import deque
import itertools as it
import sys
import math

sys.setrecursionlimit(1000000)

INF = 10 ** 18
MOD = 10 ** 9 + 7

N = input()
H = map(int, raw_input().split())
num = ans = 0
for i in range(N):
    if H[i] >= num:
        ans += 1
    num = max(num, H[i])
print ans