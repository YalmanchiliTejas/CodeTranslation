import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd
import bisect

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

N = INT()
A = [INT() for _ in range(N)]


seq = A[::-1]
LIS = [seq[0]]
for i in range(1, len(seq)):
	if seq[i] >= LIS[-1]:
		LIS.append(seq[i])
	else:
		LIS[bisect.bisect(LIS, seq[i])] = seq[i]

print(len(LIS))
