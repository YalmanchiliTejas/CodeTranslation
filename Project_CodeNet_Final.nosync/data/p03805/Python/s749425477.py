# -*- coding: utf-8 -*-
import itertools
N, M = map(int, input().split())
edges = [input().replace(" ", "") for i in range(M)]
res = 0
for l in itertools.permutations(list(range(1,N+1,1))):
    if l[0]!=1:
        continue
    for i in range(len(l)-1):
        e = str(min(l[i], l[i+1])) + str(max(l[i], l[i+1]))
        if not e in edges:
            break
    else:
        res += 1
print(res)
