def dfs(v,N,visited):
    allvis=True
    for i in range(N):
        if visited[i]==False:
            allvis=False
    if allvis:
        return 1
    ret=0
    
    for i in range(N):
        if graph[v][i]==False:
            continue
        if visited[i]:
            continue
        visited[i]=True
        ret+=dfs(i,N,visited)
        visited[i]=False
    return ret



N,M = map(int, input().strip().split())
graph = [[False] * N for i in range(N)]
for i in range(M):
    a,b=map(int,input().strip().split())
    graph[a-1][b-1]=True
    graph[b-1][a-1]=True
    

visited=[False]*N
visited[0]=True

print(dfs(0,N,visited))