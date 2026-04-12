import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, tan, asin, acos, atan, radians, degrees#, log2
from itertools import accumulate, permutations, combinations, combinations_with_replacement, product, groupby
from operator import itemgetter, mul
from copy import deepcopy
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
mod = 10**9 + 7
#from decimal import *

N = INT()
A = [INT() for _ in range(N)]

A.sort()

if N%2 == 0:
	a = A[:N//2]
	b = A[N//2:]

	print((2*sum(b)-b[0]) - (2*sum(a)-a[-1]))

else:
	a1 = A[:N//2]
	b1 = A[N//2:]

	ans1 = (2*sum(b1)-b1[0]-b1[1]) - 2*sum(a1)

	a2 = A[:-(-N//2)]
	b2 = A[-(-N//2):]

	ans2 = (2*sum(b2)) - (2*sum(a2)-a2[-1]-a2[-2])

	print(max(ans1, ans2))

