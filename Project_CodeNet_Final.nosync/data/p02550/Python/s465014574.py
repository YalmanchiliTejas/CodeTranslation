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

N, X, M = mi()

if X == 0:
    print(0)
    sys.exit()
if M == 1 or N == 1:
    print(X)
    sys.exit()

ans = 0
ls = []

s = set()
num = X
cur = 0
f = 0
while not num in s:
    s.add(num)
    cur += 1
    ls.append(num)
    if cur == N:
        f = 1
        break

    num = num**2%M
    if num == 0:
        f = 1
        break
    if num == 1:
        f = 2
        break
if f == 1:
    print(sum(ls[:min(cur, N)]))
    sys.exit()
m = [0] + list(accumulate(ls))
if f == 2:
    print(m[-1] + (N-len(ls)))
    sys.exit()

i = ls.index(num)
b = ls[i:]

a = (N-i)//len(b)

ind = (N-i) - a*len(b)

print(sum(ls[:i]) + sum(b)*a + sum(b[:ind]))