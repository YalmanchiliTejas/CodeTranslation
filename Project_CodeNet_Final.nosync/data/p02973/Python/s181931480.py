import bisect
import collections
import copy
import functools
import heapq
import math
import sys
from collections import deque
from collections import defaultdict
input = sys.stdin.readline
sys.setrecursionlimit(10**9)
MOD = 10**9+7


N = int(input())
seq = [int(input()) for _ in range(N)]
LIS = deque([seq[0]])
for i in range(1,len(seq)):
    if seq[i] <= LIS[0]:
        LIS.appendleft(seq[i])
    else:
        LIS[bisect.bisect_left(LIS, seq[i])-1] = seq[i]

print(len(LIS))