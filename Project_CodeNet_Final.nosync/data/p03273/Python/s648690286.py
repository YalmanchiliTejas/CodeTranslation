import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians#, log2
from itertools import accumulate, permutations, combinations, combinations_with_replacement, product, groupby
from operator import itemgetter, mul
from copy import deepcopy, copy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left, insort, insort_left
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
#import numpy as np
#from decimal import *

H, W = MAP()
a = [input() for _ in range(H)]

ans = []
tate = []
yoko = []

for i in range(H):
	if a[i].count("#") >= 1:
		yoko.append(i)

for i in range(W):
	for j in range(H):
		if a[j][i] == "#":
			tate.append(i)
			break

for y in yoko:
	tmp = ""
	for t in tate:
		tmp += a[y][t]
	ans.append(tmp)

print(*ans, sep="\n")
