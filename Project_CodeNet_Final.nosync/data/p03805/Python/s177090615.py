# -*- coding: utf-8 -*-
import sys,copy,math,heapq,itertools as it,fractions,re,bisect,collections as coll

def solve(k, cnt):
    if cnt == N: return 1
    used[k] = True
    res = 0
    for i in xrange(N):
        if used[i]: continue
        if G[k][i] == 0: continue
        res += solve(i, cnt + 1)
    used[k] = False
    return res

N, M = map(int, raw_input().split())
used = [False]*N
G = [[0]*N for i in xrange(N)]
for i in xrange(M):
    a, b = map(int, raw_input().split())
    a -= 1; b -= 1;
    G[a][b] = G[b][a] = 1

print solve(0, 1)

