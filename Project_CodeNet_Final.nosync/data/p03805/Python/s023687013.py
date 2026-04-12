#!/usr/bin/env python3
#ABC54 C

import sys
sys.setrecursionlimit(10000000)
from itertools import permutations

n,m = map(int,input().split())
G = [[] for _ in range(n)]

for _ in range(m):
    a,b = map(int,input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)
s = [i for i in range(n)]
t = list(permutations(s))
ans = 0
for i in t:
    if i[0] == 0:
        for j in range(n-1):
            if i[j+1] not in G[i[j]]:
                break
        else:
            ans += 1
print(ans)
