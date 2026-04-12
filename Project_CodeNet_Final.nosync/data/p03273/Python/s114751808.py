import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, log2
from itertools import accumulate, permutations, combinations, combinations_with_replacement, product, groupby
from operator import itemgetter, mul
from copy import deepcopy, copy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
from fractions import gcd
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

H, W = MAP()
s = [input() for _ in range(H)]
s2 = []

for x in s:
	if x == "." * W:
		continue
	s2.append(x)

#print(s2)

check = [1]*W

for i in range(len(s2)):
	for j in range(W):
		if s2[i][j] == "#":
			check[j] *= 0
#print(check)

for i in range(len(s2)):
	for j in range(W):
		if check[j] == 0:
			print(s2[i][j], end = "")
	print()