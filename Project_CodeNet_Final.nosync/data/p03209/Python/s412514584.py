from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
from itertools import permutations, accumulate, combinations, combinations_with_replacement
from math import sqrt, ceil, floor, factorial
from bisect import bisect_left, bisect_right, insort_left, insort_right
from copy import deepcopy
from operator import itemgetter
from functools import reduce
from fractions import gcd
import sys
def input(): return sys.stdin.readline().rstrip()
def I(): return int(input())
def Is(): return map(int, input().split())
def LI(): return list(map(int, input().split()))
def TI(): return tuple(map(int, input().split()))
def IR(n): return [I() for _ in range(n)]
def LIR(n): return [LI() for _ in range(n)]
def TIR(n): return [TI() for _ in range(n)]
def S(): return input()
def Ss(): return input().split()
def LS(): return list(input())
def SR(n): return [S() for _ in range(n)]
def SsR(n): return [Ss() for _ in range(n)]
def LSR(n): return [LS() for _ in range(n)]
sys.setrecursionlimit(10**6)
MOD = 10**9+7
INF = 10**18
# ----------------------------------------------------------- #

n, x = Is()
Blen = [0]*(n+1)
P = [0]*(n+1)
Blen[0] = 1
P[0] = 1
for i in range(1, n):
    Blen[i] = Blen[i-1]*2 + 3
    P[i] = P[i-1]*2 + 1
def burger(i, y):
    if i == 0:
        return 0 if y <= 0 else 1
    if y <= Blen[i-1] + 1:
        return burger(i-1, y-1)
    else:
        return P[i-1] + 1 + burger(i-1, y-Blen[i-1]-2)
print(burger(n, x))
