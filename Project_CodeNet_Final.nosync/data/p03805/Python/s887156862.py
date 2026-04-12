def dfs(v, N, visited):
    all_visited = True

    for i in range(N):
        if visited[i] == False:
            all_visited = False

    if all_visited:
        return 1

    ret = 0
    for i in range(N):
        if graph[v][i] == False: continue
        if visited[i]: continue

        visited[i] = True
        ret += dfs(i, N, visited)
        visited[i] = False

    return ret


N, M = map(int, input().split())

graph = [[False for _ in range(8)] for _ in range(8)]


for i in range(M):
    a, b = map(int, input().split())
    graph[a-1][b-1] = True
    graph[b-1][a-1] = True

visited = [False for _ in range(N)]
visited[0] = True

print(dfs(0, N, visited))
