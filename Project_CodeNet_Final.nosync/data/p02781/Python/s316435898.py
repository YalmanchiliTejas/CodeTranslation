import sys, re
from collections import deque, defaultdict, Counter
from math import log10, ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import accumulate, permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
from fractions import gcd
from heapq import heappush, heappop
from functools import reduce
import numpy as np

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

N = input()
K = INT()
L = len(N)
dp = [[[0]*2 for _ in range(4)] for _ in range(L+1)]
dp[0][0][0] = 1
for i in range(L):
	for j in range(4):
		for k in range(2):
			nd = int(N[i])
			for d in range(10):
				ni, nj, nk = i+1, j, k
				if d != 0:
					nj += 1
				if nj > K:
					continue
				if k == 0:
					if d > nd:
						continue
					if d < nd:
						nk = 1
				dp[ni][nj][nk] += dp[i][j][k]
ans = dp[L][K][0] + dp[L][K][1]
print(ans)
