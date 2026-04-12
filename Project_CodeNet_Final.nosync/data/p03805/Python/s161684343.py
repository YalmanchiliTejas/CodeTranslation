def dfs(visted, graph, cur, count):
    n = len(visited)

    allNodeVisited = True
    for i in range(1, n):
        if visited[i] is False:
            allNodeVisited = False
            break

    if allNodeVisited:
        count += 1
        return count

    for i in range(1, n):
        if cur != i and visited[i] is False and graph[cur][i] == 1:
            visited[i] = True
            count = dfs(visited, graph, i, count)
            visited[i] = False

    return count


n, m = map(int, input().split())
visited = [False] * (n + 1)

graph = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
for i in range(m):
    frm, to = map(int, input().split())
    graph[frm][to] = graph[to][frm] = 1


count = 0
visited[1] = True
count = dfs(visited, graph, 1, count)

print(count)
