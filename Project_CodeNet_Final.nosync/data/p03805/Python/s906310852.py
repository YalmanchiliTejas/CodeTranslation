# input
N, M = map(int, input().split())
G = [list(map(int, input().split())) for _ in range(M)]
edges = [set() for _ in range(N)]

for a, b in G:
    edges[a - 1].add(b - 1)
    edges[b - 1].add(a - 1)

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
