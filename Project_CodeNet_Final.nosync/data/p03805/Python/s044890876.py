# -*- coding: utf-8 -*-
from itertools import permutations
from collections import defaultdict

n,m = map(int, input().split())
edge = defaultdict(lambda: set([]))
for _ in range(m):
    a,b = map(int, input().split())
    edge[a].add(b)
    edge[b].add(a)

def check(p):
    for i in range(n-1):
        if p[i+1] not in edge[p[i]]:
            return False
    return True

res = 0
for r in permutations(range(2,n+1), n-1):
    if check([1]+list(r)):
        res += 1
print(res)