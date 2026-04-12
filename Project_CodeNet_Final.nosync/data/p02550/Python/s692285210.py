import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, gcd
from itertools import accumulate, permutations, combinations, product, groupby, combinations_with_replacement
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
from heapq import heappush, heappop
from functools import reduce
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def ZIP(n): return zip(*(MAP() for _ in range(n)))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

N, X, M = MAP()
visited = [0]*M
now = X
cnt = 0
l = []

while not visited[now]:
    l.append(now)
    visited[now] = True
    now = (now*now)%M
    cnt += 1
    if cnt == N:
        print(sum(l))
        exit()

idx = l.index(now)
loop = l[idx:]
loop_cnt = len(loop)
loop_sum = sum(loop)

cnt, m = divmod(N-(len(l)-loop_cnt), len(loop))
ans = sum(l[:idx])+loop_sum*cnt+sum(loop[:m])
print(ans)
