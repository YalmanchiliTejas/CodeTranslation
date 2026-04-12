def dfs(i):
    if all(visited):
        global ans
        ans += 1
        return
    for j in range(N):
        if g[i][j] and not visited[j]:
            visited[j] = True
            dfs(j)
            visited[j] = False

N, M = map(int, input().split())
g = [[False] * N for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    g[a-1][b-1] = True
    g[b-1][a-1] = True

ans = 0
visited = [False] * N
visited[0] = True
dfs(0)
print(ans)