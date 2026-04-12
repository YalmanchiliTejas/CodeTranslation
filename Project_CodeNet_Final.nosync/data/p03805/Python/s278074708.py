N, M = list(map(int,input().split()))
graph = [[-1 for i in range(N)] for i in range(N)]
for i in range(M):
    a, b = list(map(int,input().split()))
    graph[a - 1][b - 1] = 1
    graph[b - 1][a - 1] = 1
    
def dfs(node, depth):
    global visited
    global ans
    if depth == N - 1:
        if sum(visited) == N:
            ans += 1
        return
    for i in range(1, N):
        if graph[node][i] == 1 and visited[i] == -1:
            visited[i] = 1
            dfs(i, depth + 1)
            visited[i] = -1
            
visited = [-1 for i in range(N)]
visited[0] = 1

ans = 0
dfs(0, 0)

print(ans)