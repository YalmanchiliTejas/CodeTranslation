import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import accumulate, permutations, combinations, product, islice
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
from fractions import gcd
from heapq import heappush, heappop
from functools import reduce, lru_cache
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def ZIP(n): return zip(*(MAP() for _ in range(n)))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10**9 + 7

N = INT()
a = LIST()

dp = [[0]*3010 for _ in range(3010)]

for i in range(1, N+1):  # 区間幅
	for j in range(N-i+1):  # 左端
		k = j + i

		if (N-i)%2 == 0:  # 先手番
			dp[j][k] = max(dp[j+1][k]+a[j], dp[j][k-1]+a[k-1])
		else:
			dp[j][k] = min(dp[j+1][k]-a[j], dp[j][k-1]-a[k-1])

print(dp[0][N])
