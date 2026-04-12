from collections import defaultdict, deque
import sys, heapq, bisect, math, itertools, string, queue, copy, time
from fractions import gcd
import numpy as np
sys.setrecursionlimit(10**8)
INF = float('inf')
MOD = 10**9+7
EPS = 10**-7
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())


ans = 0
N, M = map(int, input().split())
path = [[False]*N for _ in range(N)]
# 0 to N-1, N nodes
for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    path[a][b] = True
    path[b][a] = True


for i in itertools.permutations(range(N), N):
    if i[0] == 0:
        for j in range(N-1):
            if not path[i[j]][i[j+1]]:
                break
            if j == N-2:
                ans += 1

print(ans)