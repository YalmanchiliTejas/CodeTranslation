# -*- coding: utf-8 -*-
# E - Sequence Decomposing
import sys 
from bisect import bisect_left
from collections import deque

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
N = int(readline())
A = list(map(int,read().split()))


INF = 10**31
q = deque([])

for a in A:
    idx = bisect_left(q, a)
    if idx == 0:
        q.appendleft(a)
    else:
        q[idx-1] = a
print(len(q))