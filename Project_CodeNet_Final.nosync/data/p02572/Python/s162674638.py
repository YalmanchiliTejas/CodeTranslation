import sys
from sys import exit
from math import gcd, factorial, ceil, floor, sqrt
from bisect import bisect_left, bisect_right
from copy import deepcopy
from heapq import heapify, heappop, heappush
from itertools import permutations, combinations, product, accumulate
from collections import defaultdict, deque, Counter
sys.setrecursionlimit(10**7)

ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

N = ii()
A = li()
mod = 10**9+7

ans = 0
m = list(accumulate(A))
for i, x in enumerate(m[:-1]):
    ans += ((A[i]%mod) * ((m[-1] - m[i])%mod))%mod
    ans %= mod
print(ans)
