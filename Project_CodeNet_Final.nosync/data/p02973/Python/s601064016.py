from itertools import*
from math import*
from collections import*
from heapq import*
from bisect import bisect_left,bisect_right,bisect
from copy import deepcopy
inf = float("inf")
mod = 10**9+7
from functools import reduce
import sys
sys.setrecursionlimit(10**7)

N = int(input())
LIS = []
for i in range(N):
    a =- int(input())
    idx = bisect(LIS,a)
    if idx == len(LIS):
        LIS.append(a)
    else:
        LIS[idx]=a
print(len(LIS))