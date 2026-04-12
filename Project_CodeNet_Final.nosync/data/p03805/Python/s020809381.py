#coding: utf-8
import math
import heapq
import bisect
import numpy as np
from collections import Counter, deque
import itertools
#from scipy.misc import comb

N,M = map(int, input().split())

G = [[] for _ in range(N)]
for _ in range(M):
    a,b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

l = [i for i in range(1,N)]

ans = 0
for v in itertools.permutations(l, N-1):
    tmp = 0
    a = 0
    for b in v:
        if b in G[a]: tmp += 1
        a = b

    if tmp == N-1: ans += 1

print(ans)