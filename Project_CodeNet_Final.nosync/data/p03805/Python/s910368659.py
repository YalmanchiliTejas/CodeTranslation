# -*- coding: utf-8 -*-

import copy

n,m = list(map(int,input().split()))
rinset = [[0]*(n+1) for _ in range(n+1)]
for _ in range(m):
    a,b = list(map(int,input().split()))
    rinset[a][b]=b
    rinset[b][a]=a
cnt = 0
def solve(start,visitted):
    global cnt
    visitted = copy.deepcopy(visitted)
    visitted.append(start)
    if len(visitted) == n:
        cnt+=1
        return
    next_start=[i for i in rinset[start] if (i>1 and i not in visitted)]
    for i in next_start:
        solve(i,visitted)

solve(1,[])
print(cnt)
