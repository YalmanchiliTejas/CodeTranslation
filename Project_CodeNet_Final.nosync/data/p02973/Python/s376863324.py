import sys
import itertools
# import numpy as np
import time
import math
import heapq
from collections import defaultdict
sys.setrecursionlimit(10 ** 7)
 
INF = 10 ** 9 + 7
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

# map(int, input().split())

MOD = 10 ** 4 + 7

N = int(input())

A = [0] * N
for i in range(N):
    A[i] = int(input())

from collections import deque
d = deque([])
for a in A:
    l = -1
    r = len(d)
    while r - l > 1:
        m = l + (r - l) // 2
        if d[m] >= a:
            r = m
        else:
            l = m
    if r == 0:
        d.appendleft(a)
    else:
        d[r - 1] = a
print(len(d))