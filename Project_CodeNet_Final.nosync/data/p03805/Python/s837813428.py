import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

N, M = MAP()
ab = [LIST() for _ in range(M)]

graph = [[0]*N for _ in range(N)]
for a, b in ab:
	graph[a-1][b-1] = 1
	graph[b-1][a-1] = 1

ans = 0
for i in permutations(range(1, N)):
	i = list(i)
	i.insert(0, 0)
	# print(i)
	for j in range(N-1):
		if graph[i[j]][i[j+1]] != 1:
			break
	else:
		ans += 1
print(ans)
