import sys, re, os
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd
 
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def S_MAP(): return map(str, input().split())
def LIST(): return list(map(int, input().split()))
def S_LIST(): return list(map(str, input().split()))
 
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

N, M = MAP()
L = [LIST() for i in range(M)]

graph = defaultdict(list)
# E = defaultdict(list)
rinsetsu = [[0] * N for i in range(N)]

for a, b in L:
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)
    rinsetsu[a-1][b-1] = 1
    rinsetsu[b-1][a-1] = 1

per = list(permutations([n for n in range(1, N)]))
# print(permu)
permu = []
for p_list in per:
    p_list = [0] + list(p_list)
    permu.append(p_list)

ans = 0

for p in permu:
    for i in range(N-1):
        # print(p[i], p[i+1])
        if rinsetsu[p[i]][p[i+1]] != 1:
            break
    else:
        ans += 1
print(ans)
    
