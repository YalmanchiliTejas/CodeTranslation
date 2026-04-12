#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

n=int(input())
A=[int(input()) for i in range(n)]
data=collections.deque()
for i, ai in enumerate(A):
    k=bisect.bisect_left(data,ai)
    if k==0:
        data.appendleft(ai)
    else:
        data[k-1]=ai
print(len(data))