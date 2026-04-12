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

#連結リスト
graph = [[] for _ in range(N)]

for a, b in ab:
	graph[a-1].append(b-1)
	graph[b-1].append(a-1)

#print(graph)
ans = 0

for x in permutations(range(1, N)):
	tmp = 0
	for i in range(N-1):
		if x[i] in graph[tmp]:
			tmp = x[i]
		else:
			break
	else:
		ans += 1

print(ans)
