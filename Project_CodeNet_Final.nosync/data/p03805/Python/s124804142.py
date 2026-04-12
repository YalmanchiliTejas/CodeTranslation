# -*- coding: utf-8 -*-
N, M = map(int, input().split())

ab = []
for _ in range(M):
    ab.append(list(map(int, input().split())))

map_org = [[0 for _ in range(N)] for _ in range(N)]

for a, b in ab:
    map_org[a-1][b-1] = 1
    map_org[b-1][a-1] = 1

def dfs(v):
    visited[v] = 1
    if sum(visited) == N:
        return 1

    ret = 0    
    for i in range(N):
        if map_org[v][i] == 1:
            if visited[i] == 0:
                ret += dfs(i)
                visited[i] = 0
    return ret


visited = [0 for _ in range(N)]
print(dfs(0))