# -*- coding: utf-8 -*-
n,m = map(int, input().split())
graph = [[] for j in range(n)]

for i in range(m):
    a,b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

used = [False]*n
used[0] = True

def DFS(v,used):
    if all(used):
        return 1
    ans = 0
    for i in graph[v]:
        if used[i]:
            continue
        used[i] = True
        ans += DFS(i,used)
        used[i] = False
    return ans
  
print(DFS(0,used))
