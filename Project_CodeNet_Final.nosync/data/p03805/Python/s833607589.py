#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10**7)
import bisect
import heapq
import itertools
import math
from collections import Counter, defaultdict, deque
from copy import deepcopy
from decimal import Decimal
from math import gcd
from operator import add, itemgetter, mul, xor
def cmb(n,r,mod):
  bunshi=1
  bunbo=1
  for i in range(r):
    bunbo = bunbo*(i+1)%mod
    bunshi = bunshi*(n-i)%mod
  return (bunshi*pow(bunbo,mod-2,mod))%mod
mod = 10**9+7
def I(): return int(input())
def LI(): return list(map(int,input().split()))
def MI(): return map(int,input().split())
def LLI(n): return [list(map(int, input().split())) for _ in range(n)]

n,m = MI()
graph = [[] for _ in range(n+1)]
for i in range(m):
    a,b = MI()
    graph[a].append(b)
    graph[b].append(a)
visited = [False]*(n+1)
visited[0] = True
visited[1] = True
def dfs(v,visited):
    if all(visited):
        return 1
    ans = 0
    for i in graph[v]:
        if visited[i]:
            continue
        visited[i] = True
        ans += dfs(i,visited)
        visited[i] = False
    return ans
print(dfs(1,visited))
