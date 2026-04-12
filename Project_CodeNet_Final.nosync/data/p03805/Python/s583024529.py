N, M = map(int,input().split())
graph = [[False for i in range(N)] for j in range(N)]
for i in range(M):
    a, b = map(int,input().split())
    graph[a-1][b-1] = graph[b-1][a-1] = True

def dfs(v,n,visited):
    if not False in visited:
        return 1
    ret = 0
    for i in range(n):
        if not graph[v][i]:
            continue
        if visited[i]:
            continue
        visited[i] = True
        ret += dfs(i,n,visited)
        visited[i] = False
    return ret

visited = [False]*N
visited[0] = True
print(dfs(0,N,visited))

