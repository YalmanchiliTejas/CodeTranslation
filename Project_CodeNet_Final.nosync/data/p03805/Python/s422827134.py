N, M = map(int, input().split())
graph = [[False for _ in range(N+1)] for __ in range(N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    graph[a][b] = True
    graph[b][a] = True

def dfs(v, visited):
    if len(visited) == N:
        return 1
    ret = 0
    for i in range(1,N+1):
        if graph[v][i] and not i in visited:
            visited[i] = True
            ret += dfs(i, visited)
            visited.pop(i)
    return ret

print(dfs(1, {1: True}))