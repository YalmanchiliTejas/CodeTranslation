import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, atan, degrees
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd
from bisect import bisect
import numpy as np

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

N = INT()
s = input()

search = [
["S"]+["_"]*(N-1), 
["S"]+["_"]*(N-1), 
["W"]+["_"]*(N-1),
["W"]+["_"]*(N-1)
]

if s[0] == "o":
	search[0][1] = "S"
	search[0][-1] = "S"
	search[1][1] = "W"
	search[1][-1] = "W"
	search[2][1] = "W"
	search[2][-1] = "S"
	search[3][1] = "S"
	search[3][-1] = "W"
else:
	search[0][1] = "S"
	search[0][-1] = "W"
	search[1][1] = "W"
	search[1][-1] = "S"
	search[2][1] = "W"
	search[2][-1] = "W"
	search[3][1] = "S"
	search[3][1] = "S"

for lis in search:
	for i in range(N):
		# print(i, lis)
		if s[i] == "o" and lis[i] == "S":
			if lis[(i+1)%N] != "_" and lis[i-1] != lis[(i+1)%N]:
				break
			if lis[(i+1)%N] == "_":
				lis[i+1] = lis[i-1]
		elif s[i] == "x" and lis[i] == "S":
			if lis[(i+1)%N] != "_" and lis[i-1] == lis[(i+1)%N]:
				break
			if lis[(i+1)%N] == "_":
				if lis[i-1] == "W":
					lis[i+1] = "S"
				else:
					lis[i+1] = "W"

		elif s[i] == "o" and lis[i] == "W":
			if lis[(i+1)%N] != "_" and lis[i-1] == lis[(i+1)%N]:
				break
			if lis[(i+1)%N] == "_":
				if lis[i-1] == "W":
					lis[i+1] = "S"
				else:
					lis[i+1] = "W"
			
		elif s[i] == "x" and lis[i] == "W":
			if lis[(i+1)%N] != "_" and lis[i-1] != lis[(i+1)%N]:
				break
			if lis[(i+1)%N] == "_":
				lis[i+1] = lis[i-1]

	else:
		print(*lis, sep="")
		break
else:
	print(-1)
