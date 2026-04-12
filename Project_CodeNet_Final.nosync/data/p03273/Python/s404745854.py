import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
MOD = 10 ** 9 + 7

H, W = MAP()
a = [list(input()) for _ in range(H)]

# a = [s for s in a if s != ["."]*W]

# b = [[0]*len(a) for _ in range(len(a[0]))]
# for i in range(len(a)):
# 	for j in range(len(a[0])):
# 		b[j][i] = a[i][j]

# b = [s for s in b if s != ["."]*len(b[0])]

# c = [[0]*len(b) for _ in range(len(b[0]))]

# for i in range(len(b)):
# 	for j in range(len(b[0])):
# 		c[j][i] = b[i][j]

# for s in c:
# 	print("".join(s))

gyou = set()
retu = set()

for i in range(H):
	for j in range(W):
		if a[i][j] == "#":
			retu.add(j)
			gyou.add(i)


for g in gyou:
	for r in retu:
		print(a[g][r], end="")
	print()
