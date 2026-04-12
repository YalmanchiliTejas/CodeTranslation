import sys, math, itertools, bisect, copy, re
from collections import Counter, deque, defaultdict

# from itertools import accumulate, permutations, combinations, takewhile, compress, cycle
# from functools import reduce
# from math import ceil, floor, log10, log2, factorial
# from pprint import pprint

INF = float('inf')
MOD = 10 ** 9 + 7
EPS = 10 ** -7
sys.setrecursionlimit(1000000)

# N = int(input())
# N,M = [int(x) for x in input().split()]
# V = [[0] * 100 for _ in range(100)]
# A = [int(input()) for _ in range(N)]
# DP = [[0] * 100 for _ in range(100)]
# DP = defaultdict(lambda: float('inf'))

import heapq

N = int(input())
A = []
for _ in range(N):
    A.append(-int(input()))

B = []

for a in A:
    i = bisect.bisect_right(B, a)
    if i != len(B):
        B[i] = a
    else:
        B.append(a)

# print(B)
print(len(B))

pass
