#!/usr/bin/env python

from collections import deque
import itertools as it
import sys
import math

sys.setrecursionlimit(10000000)

H, W = map(int, raw_input().split())

A = []

for i in range(H):
    A.append(raw_input())

H_flag = [0] * H
W_flag = [0] * W

for i in range(H):
    for j in range(W):
        if A[i][j] == '.':
            W_flag[j] += 1
            H_flag[i] += 1

for i in range(H):
    if H_flag[i] != W:
        S = ''
        for j in range(W):
            if W_flag[j] != H:
                S += A[i][j]
        print S