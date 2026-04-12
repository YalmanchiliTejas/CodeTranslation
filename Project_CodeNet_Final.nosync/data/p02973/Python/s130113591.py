
import heapq
from collections import defaultdict, deque
# from math import ceil, factorial, gcd
from itertools import accumulate, permutations
import sys
import bisect


sys.setrecursionlimit(10 ** 7)
INF = float("inf")
MOD = 10 ** 9 + 7

si = lambda: input().strip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
msi = lambda: map(str, input().split())
lmii = lambda: list(map(int, input().split()))
lmsi = lambda: list(map(str, input().split()))
smii = lambda: sorted(map(int, input().split()))
# ----------

N = ii()
A = []
for i in range(N):
    A.append(ii())

d = deque()

for a in A:
    p = bisect.bisect_left(d, a)
    if p == 0:
        d.appendleft(a)
        continue
    d[p-1] = a

print(len(d))
