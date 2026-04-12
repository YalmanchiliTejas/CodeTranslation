def dfs(ver, p):
    global visited, ans
    if p == N:
        ans += 1
        return
    for i in range(N):
        if graph[ver][i] == 1 and visited[i] != 1:
            visited[i] = 1
            dfs(i, p+1)
            visited[i] = 0

N, M = map(int,input().split())

graph = [[0] * N for _ in range(N)]

for i in range(M):
    a, b = map(int,input().split())
    graph[a-1][b-1] = 1
    graph[b-1][a-1] = 1

ans = 0
visited = [0] * N
visited[0] = 1

dfs(0, 1)

print(ans)