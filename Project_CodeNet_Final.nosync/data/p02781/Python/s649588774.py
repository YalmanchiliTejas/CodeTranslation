#!/usr/bin/env python

from collections import deque, defaultdict
import itertools as ite
import sys
import math
from decimal import *

sys.setrecursionlimit(1000000)

INF = 10 ** 18
MOD = 10 ** 9 + 7

N = raw_input()
K = input()
K_ = K

DP = [[0] * 110 for i in range(110)]
DP[0][0] = 1

for i in range(1, 110):
    DP[i][0] = 1
    for j in range(1, 110):
        DP[i][j] = DP[i - 1][j] + DP[i - 1][j - 1] * 9

ans = 0
for i in range(len(N)):
    if N[i] != '0':
        ans += DP[len(N) - i - 1][K]
        ans += (int(N[i]) - 1) * DP[len(N) - i - 1][K - 1]
    if N[i] != '0':
        K -= 1
        if K < 1:
            ans += 1
            break

print ans