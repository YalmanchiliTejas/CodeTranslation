import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, tan, asin, acos, atan, radians, degrees, log2, gcd
from itertools import accumulate, permutations, combinations, combinations_with_replacement, product, groupby
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left, insort, insort_left
from heapq import heappush, heappop
from functools import reduce
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def ZIP(n): return zip(*(MAP() for _ in range(n)))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7 
#mod = 998244353
from decimal import *
#import numpy as np
#decimal.getcontext().prec = 10

N, X = MAP()

L = [0]*(N+1) #レベルiにおける全体の枚数
L[0] = 1

P = [0]*(N+1) #レベルiにおけるパティの枚数
P[0] = 1

for i in range(1, N+1):
	L[i] = L[i-1]*2 + 3
	P[i] = P[i-1]*2 + 1

def solve(i, x):  #レベルiの下からX層におけるパティの枚数
	if i == 0:
		if 0 < x:
			return 1
		else:
			return 0

	if x-1 <= L[i-1]:
		return solve(i-1, x-1)
	else:
		return P[i-1] + 1 + solve(i-1, x-L[i-1]-2)

print(solve(N, X))


