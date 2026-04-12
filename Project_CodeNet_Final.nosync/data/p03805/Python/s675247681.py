def dfs(v, n, visited, g):
    if False not in visited:
        return 1

    result = 0

    for i in range(n):
        if not g[v][i]:
            continue
        if visited[i]:
            continue
        visited[i] = True
        result += dfs(i, n, visited, g)
        visited[i] = False

    return result


n, m = [int(i) for i in input().split()]
g = [[False] * n for i in range(n)]
for i in range(m):
    a, b = [int(i) for i in input().split()]
    g[a-1][b-1] = True
    g[b-1][a-1] = True

visited = [False] * n
visited[0] = True
print(dfs(0, n, visited, g))