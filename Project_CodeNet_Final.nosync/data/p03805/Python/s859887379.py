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
    if all(used):
        return 1
    ans = 0
    for i in range(n):
        if used[i]:
            continue
        if graph[i,v] == 0:
            continue
        used[i] = True
        ans += DFS(i,used)
        used[i] = False
    return ans
  
print(DFS(0,used))