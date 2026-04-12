import sys, re
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, tan, asin, acos, atan, radians, degrees, log2
from collections import deque, defaultdict, Counter
from itertools import accumulate, permutations, combinations, combinations_with_replacement, product, groupby
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
from fractions import gcd
from heapq import heappush, heappop, heapify
from functools import reduce
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def ZIP(n): return zip(*(MAP() for _ in range(n)))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

N, M = MAP()
ab = [LIST() for _ in range(M)]

#隣接行列
contact = [[0]*N for _ in range(N)]

for a, b in ab:
	contact[a-1][b-1] = 1
	contact[b-1][a-1] = 1

A = list(x for x in range(1, N))
ans = 0

for X in permutations(A, N-1):
	#print(X)
	tmp = 0
	for y in X:
		if contact[tmp][y] == 1:
			tmp = y
		else:
			break
	else:
		#print("成功")
		ans += 1

print(ans)
