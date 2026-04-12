def dfs(s, n, visited):
    all_visited = True
    for i in range(n):
        if not visited[i]: all_visited = False
    if all_visited: return 1

    ret = 0
    for i in range(n):
        if not graph[s][i]: continue
        if visited[i]: continue
        visited[i] = True
        ret += dfs(i, n, visited)
        visited[i] = False

    return ret


n, m = map(int, input().split())

graph = [[False for i in range(n)] for j in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    graph[a-1][b-1] = graph[b-1][a-1] = True

visited = [False for i in range(n)]
visited[0] = True

print(dfs(0, n, visited))