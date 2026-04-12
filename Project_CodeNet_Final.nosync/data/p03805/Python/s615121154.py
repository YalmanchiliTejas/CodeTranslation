# -*- coding: utf-8 -*-

from functools import reduce

N, M = map(int, input().split())

# 隣接行列
edges = [[False for j in range(N)] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    edges[a-1][b-1] = True
    edges[b-1][a-1] = True
# print(edges)

def DFS(v, N, visited):
    # 全て訪問済みかチェック
    all_visited = True
    for i in range(N):
        if not visited[i]:
            all_visited = False

    if all_visited:
        return 1

    ret = 0

    for i in range(N):
        if not edges[v][i]:
            continue
        if visited[i]:
            continue

        visited[i] = True
        ret += DFS(i, N, visited)
        visited[i] = False

    return ret

visited = [False for i in range(N)]
visited[0] = True
print(DFS(0, N, visited))
