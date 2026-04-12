(n, m) = map(int, input().split())
graph = {}
for _ in range(m):
    (a, b) = map(int, input().split())
    if not a in graph:
        graph[a] = []
    graph[a].append(b)
    if not b in graph:
        graph[b] = []
    graph[b].append(a)
is_visited = [False for _ in range(len(graph.keys()))]


def dfs(count, graph, is_visited, v_id):
    if all(is_visited):
        return 1
    sum = 0
    for neighbor in graph[v_id]:
        if is_visited[neighbor - 1]:
            continue
        is_visited[neighbor - 1] = True
        sum += dfs(count, graph, is_visited, neighbor)
        is_visited[neighbor - 1] = False
    return count + sum


count = 0
is_visited[0] = True
print(dfs(count, graph, is_visited, 1))
