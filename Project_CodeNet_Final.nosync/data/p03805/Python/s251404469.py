#!/usr/bin/env python

from collections import deque
import itertools as it
import sys
import math

sys.setrecursionlimit(1000000)

INF = 10 ** 18
MOD = 10 ** 9 + 7

N, M = map(int, raw_input().split())
edge = [[False] * N for i in range(N)]

for i in range(M):
    a, b = map(int, raw_input().split())
    a, b = a - 1, b - 1
    edge[a][b] = True
    edge[b][a] = True

def func(num, used):
    if not True in used:
        return 1
    ret = 0
    for i in range(N):
        if used[i] and edge[num][i]:
            used[i] = False
            ret += func(i, used)
            used[i] = True
    return ret

print func(0, [False] + [True] * (N - 1))