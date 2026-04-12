#!/usr/bin/env python

from collections import deque
import itertools as it
import sys
import math

sys.setrecursionlimit(1000000)

INF = 10 ** 18

H, W = map(int, raw_input().split())

a = [raw_input() for _ in range(H)]
f1 = [False] * H
f2 = [False] * W

for i in range(H):
    hoge = True
    for j in range(W):
        if a[i][j] == '#':
            hoge = False
    f1[i] = hoge

for i in range(W):
    hoge = True
    for j in range(H):
        if a[j][i] == '#':
            hoge = False
    f2[i] = hoge

for i in range(H):
    if f1[i]:
        continue
    S = ""
    for j in range(W):
        if not f2[j]:
            S += a[i][j]
    print S
