#!/usr/bin/env python

import sys
import math
import itertools as it
from collections import deque

sys.setrecursionlimit(10000000)

while True:
    S = raw_input()
    if S == '#':
        break
    S = list(S)
    for i in range(len(S)):
        if S[i] in ['y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm']:
            S[i] = 1
        else:
            S[i] = 0
    ans = 0
    for i in range(len(S) - 1):
        if S[i] != S[i + 1]:
            ans += 1
    print ans
