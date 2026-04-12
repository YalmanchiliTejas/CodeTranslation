#!/usr/bin/env python

from collections import deque
import itertools as it
import sys
import math

sys.setrecursionlimit(1000000)

INF = 10 ** 18
MOD = 10 ** 9 + 7

N = input()

A = []

for i in range(N):
    A.append(input())
A.sort()

if N % 2:
    pos = N / 2
    ans = 0
    for i in range(N):
        ans += abs(A[i] - A[pos]) * 2
    ans -= min(A[pos + 1] - A[pos], A[pos] - A[pos - 1])
    print ans
else:
    pos1 = N / 2 - 1
    pos2 = N / 2
    ans = (A[pos2] - A[pos1]) * (N - 1)
    for i in range(N):
        ans += min(abs(A[i] - A[pos1]), abs(A[i] - A[pos2])) * 2
    print ans