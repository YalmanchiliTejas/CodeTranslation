import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd
from bisect import bisect

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

A, B, C, X, Y = MAP()

ans = 0
if A + B > 2 * C:
	ans += 2 * C * min(X, Y)
	idx = (X, Y).index(max(X, Y))
	left = abs(X - Y)
	if 2 * C < (A, B)[idx]:  # C を購入
		ans += 2 * C * left
	else:
		ans += (A, B)[idx] * left
else:
	ans = A * X + B * Y
print(ans)
