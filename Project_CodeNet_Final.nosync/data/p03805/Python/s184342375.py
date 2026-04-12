N, M = map(int, input().split())

G = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

visited = [0]*N
visited[0] = 1

def dfs(v, visited):
    if 0 not in visited:
        return 1

    ans = 0
    for i in G[v]:
        if visited[i] == 0:
            visited[i] = 1
            ans += dfs(i, visited)
            visited[i] = 0

    return ans

print(dfs(0, visited))