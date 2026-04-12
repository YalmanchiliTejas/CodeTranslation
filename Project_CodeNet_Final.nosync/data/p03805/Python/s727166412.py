import sys
sys.setrecursionlimit(1000000)
N, M = map(int, input().split())
G = {k: [] for k in range(N)}
for _ in range(M):
    a, b = map(int, input().split())
    # 無向グラフ
    G[a-1].append(b-1)
    G[b-1].append(a-1)

visited = [False]*N
visited[0] = True


def dfs(v):
    if all(visited):
        return 1
    r = 0
    for nv in G[v]:
        if visited[nv] is False:
            visited[nv] = True
            r += dfs(nv)
            visited[nv] = False
    return r


print(dfs(0))
