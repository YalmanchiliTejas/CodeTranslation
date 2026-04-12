nmax = 8
graph = [[0]*nmax for i in range(nmax)]
visited = [0] * nmax


def dfs(v, N, visited):
    all_visited = True
    for i in range(N):
        if visited[i] == 0:
            all_visited = False
    if all_visited:
        return 1
  
    ret = 0
    for i in range(N):
        if graph[v][i] == 0:
            continue
        if visited[i] == 1:
            continue
        visited[i] = 1
        ret += dfs(i, N, visited)
        visited[i] = 0
    return ret
      

N, M = [int(i) for i in input().split()]
for j in range(M):
    a, b = [int(j) for j in input().split()]
    graph[a-1][b-1] = graph[b-1][a-1] = 1


visited[0] = 1
print(dfs(0, N, visited))