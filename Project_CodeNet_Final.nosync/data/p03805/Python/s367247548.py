N, M = map(int, input().split())
edges = [list(map(int, input().split())) for _ in range(M)]

graph = [[None] * N for _ in range(N)]
for u, v in edges:
    graph[u - 1][v - 1] = True
    graph[v - 1][u - 1] = True

def dfs(s):    
    if all(visited):
        return 1

    cnt = 0
    for i in range(N):
        if graph[s][i] is None:
            continue

        if visited[i]:
            continue
            
        visited[i] = True
        cnt += dfs(i)
        visited[i] = False
        
    return cnt

visited = [False] * N
visited[0] = True
print(dfs(0))

