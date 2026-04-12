# -*- coding: utf-8 -*-
N,M = map(int, input().split())
G = [[] for j in range(N)]
#グラフの読み込み
for i in range(M):
    a,b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)
visited = [False]*N
visited[0] = True
#再帰
def DFS(v,visited):
    #もし全てTrueなら1を返す
    if all(visited):
        return 1
    ans = 0
    for i in G[v]:
        if visited[i]:
            continue
        visited[i] = True
        ans += DFS(i,visited)
        visited[i] = False
    return ans

print(DFS(0,visited))
