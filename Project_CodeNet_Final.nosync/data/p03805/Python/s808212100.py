def DFS(now, visited):
    ans = 0
    if all(visited):
        return 1
    for i in range(N):
        if path[now][i] and visited[i] == False:
            visited[i] = True
            ans += DFS(i, visited)
            visited[i] = False
    return ans
    


N, M = map(int, input().split())
path = [[0]*N for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    path[a-1][b-1] = 1
    path[b-1][a-1] = 1
visited = [False]*N
visited[0] = True
print(DFS(0, visited))


