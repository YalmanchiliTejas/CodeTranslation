N, M = map(int, input().split())
G = [[0] * N for _ in range(N)]
for _ in range(M):
    a, b = map(lambda x: int(x)-1, input().split())
    G[a][b] = G[b][a] = 1
visited = [False] * N


def dfs(v):
    visited[v] = True
    if all(visited):
        visited[v] = False
        return 1
    ret = 0
    for u in range(N):
        if v == u or visited[u] or G[v][u] == 0:
            continue
        ret += dfs(u)
    visited[v] = False
    return ret


print(dfs(0))
