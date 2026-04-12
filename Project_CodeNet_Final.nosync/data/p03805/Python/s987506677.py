def dfs(graph, start):
    ans = 0
    stack = [[start, 2**start]]
    visited = {}
    while stack:
        d = stack.pop()
        if d[1] == 2 ** N - 1:
            ans += 1
            continue
        for node in graph[d[0]]:
            if not (d[1] & 2 ** node):
                stack.append([node, d[1] | 2 ** node])
    return ans


N, M = map(int, input().split())
g = {i: [] for i in range(N)}
for i in range(M):
    a, b = map(int, input().split())
    g[a - 1].append(b - 1)
    g[b - 1].append(a - 1)
print(dfs(g, 0))