# -*- coding: utf-8 -*-
import numpy as np

n,m = map(int, input().split())
graph = [[0 for i in range(n)] for j in range(n)]
graph = np.array(graph)

for i in range(m):
    a,b = map(int, input().split())
    graph[a-1,b-1] = 1
    graph[b-1,a-1] = 1

used = [False]*n
used[0] = True

def DFS(v,used):
    global ans
    if all(used):
        ans += 1
        return 
    for i in range(n):
        if used[i]:
            continue
        if graph[i,v] == 0:
            continue
        used[i] = True
        DFS(i,used)
        used[i] = False
    return

ans = 0
DFS(0,used)

print(ans)