import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, tan, asin, acos, atan, radians, degrees#, log2, log
from itertools import accumulate, permutations, combinations, combinations_with_replacement, product, groupby
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left, insort, insort_left
from fractions import gcd
from heapq import heappush, heappop
from functools import reduce
from decimal import Decimal
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def ZIP(n): return zip(*(MAP() for _ in range(n)))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10**9 + 7
from decimal import *

H, W = MAP()
A = [input() for _ in range(H)]

cnt_w = sum([X.count("#") for X in A])

def DFS(y, x, cnt):
	if 0 <= x+1 <= W-1 and A[y][x+1] == "#":
			return DFS(y, x+1, cnt+1)
	elif 0 <= y+1 <= H-1 and A[y+1][x] == "#":
			return DFS(y+1, x, cnt+1)
	else:
		return (y, x, cnt)

if A[0][0] != "#":
	print("Impossible")
elif (H-1, W-1, cnt_w) == DFS(0, 0, 1):
	print("Possible")
else:
	print("Impossible")