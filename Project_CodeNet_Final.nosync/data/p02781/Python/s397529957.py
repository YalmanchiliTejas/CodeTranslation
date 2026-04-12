import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import accumulate, permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
from fractions import gcd
from heapq import heappush, heappop
from functools import reduce
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

N = input()
K = INT()

dp_co = [[0 for _ in range(3 + 1)] for _ in range(len(N) + 1)]
dp_unco = [[0 for _ in range(3 + 1)] for _ in range(len(N) + 1)]
dp_co[0][0] = 1

for i in range(len(N)):
	for j in range(4):
		for k in range(2):
			for num in range(10):
				n_i, n_j, n_k = i + 1, j, k
				if num != 0:
					n_j += 1
				if n_j > K:
					continue
				if k == 0:
					if num > int(N[i]):
						continue
					if num == int(N[i]):
						k = 0
					if num < int(N[i]):
						n_k = 1
				if n_k == 0:
					dp_co[n_i][n_j] += dp_co[i][j]
				if n_k == 1:
					if k == 0:
						dp_unco[n_i][n_j] += dp_co[i][j]
					else:
						dp_unco[n_i][n_j] += dp_unco[i][j]						

ans = dp_co[len(N)][K] + dp_unco[len(N)][K]
print(ans)