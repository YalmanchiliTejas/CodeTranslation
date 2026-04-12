import numpy as np

n, m = map(int, input().split())
graph = np.zeros((n, n), dtype=np.int8)
for _ in range(m):
    a, b = map(int, input().split())
    graph[a-1, b-1] = 1
    graph[b-1, a-1] = 1

def dfs(node, visited):
    if sum(visited) == n:
        return 1
    res = 0
    for i in range(n):
        if graph[node, i] and not visited[i]:
            visited[i] = 1
            res += dfs(i, visited)
            visited[i] = 0
    return res

print(dfs(0, [1] + [0] * (n - 1)))
