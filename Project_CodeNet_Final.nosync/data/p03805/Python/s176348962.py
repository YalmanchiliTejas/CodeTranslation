import sys

sys.setrecursionlimit(10**6)

N, M = map(int, input().split())
graph = [set([]) for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    graph[a - 1].add(b - 1)
    graph[b - 1].add(a - 1)


def dfs(graph, visited, v):
    if all(visited):
        return 1

    cnt = 0
    for u in graph[v]:
        if visited[u]:
            continue
        visited[u] = True
        cnt += dfs(graph, visited, u)
        visited[u] = False

    return cnt


visited = [False] * len(graph)
visited[0] = True
ans = dfs(graph, visited, 0)
print(ans)
