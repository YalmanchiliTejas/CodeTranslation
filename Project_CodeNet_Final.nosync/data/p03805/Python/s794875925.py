# -*- coding: utf-8 -*-
n,m = map(int, input().split())
edge = [[] for _ in range(n+1)]
for _ in range(m):
    a,b = map(int, input().split())
    a -= 1
    b -= 1
    edge[a].append(b)
    edge[b].append(a)

visited = [False for _ in range(n)]
def dfs(v):
    if all(visited):
        return 1
    res = 0
    for e in edge[v]:
        if not visited[e]:
            visited[e] = True
            res += dfs(e)
            visited[e] = False
    return res

visited[0] = True
print(dfs(0))
