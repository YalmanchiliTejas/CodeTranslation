N, M = map(int, input().split())
edges = [list(map(int, input().split())) for _ in range(M)]

graph = [[None] * N for _ in range(N)]
for x, y in edges:
    graph[x - 1][y - 1] = True
    graph[y - 1][x - 1] = True
    
def dfs(v):    
    if all(visited):
        return 1
    
    ret = 0
    for i in range(N):
        if not graph[v][i]:
            continue
        if visited[i]:
            continue
            
        visited[i] = True
        ret += dfs(i)
        visited[i] = False
        
    return ret

visited = [True] + [False] * (N - 1)
print(dfs(0))