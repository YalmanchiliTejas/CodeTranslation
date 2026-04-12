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

graph = defaultdict(list)
for _ in range(M):
	a, b = MAP()
	graph[a-1].append(b-1)
	graph[b-1].append(a-1)

#print(graph)

ans = 0
A = list(range(1, N))

for x in permutations(A, N-1):
	#print(x)
	y = [0]
	tmp = graph[0]
	for i in range(N-1):
		if x[i] in tmp and not x[i] in y:
			y.append(x[i])
			tmp = graph[x[i]]
		else:
			break
	else:
		ans += 1
		#print("成功")

print(ans)

