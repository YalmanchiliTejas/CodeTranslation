import math, sys
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from copy import deepcopy
from functools import lru_cache
from heapq import heapify, heappop, heappush
from itertools import accumulate, combinations, permutations
input = sys.stdin.readline
mod = 10**9 + 7
ns = lambda: input().strip()
ni = lambda: int(input().strip())
nm = lambda: map(int, input().split())
nl = lambda: list(map(int, input().split()))

H, W = nm()
a = [list(ns()) for _ in range(H)]

def compress(a):
    out = []
    for line in a:
        if '#' in line:
            out.append(line)
    return out

temp = compress(a)
temp2 = compress([list(i) for i in zip(*temp)])
ans = [list(i) for i in zip(*temp2)]

for line in ans:
    print(''.join(line))