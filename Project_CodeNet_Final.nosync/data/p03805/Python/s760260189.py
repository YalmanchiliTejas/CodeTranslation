N, M = map(int, input().split())
G = [list(map(int, input().split())) for _ in range(M)]
edges = [[] for _ in range(N)]
for a, b in G:
    edges[a - 1].append(b - 1)
    edges[b - 1].append(a - 1)

def dfs(start, edges, path):
    path.append(start)
    if len(path) == N:
        path.pop()
        return 1
    ans = 0
    for u in edges[start]:
        if u in path:
            continue
        ans += dfs(u, edges, path)
    path.pop()
    return ans

print(dfs(0, edges, []))