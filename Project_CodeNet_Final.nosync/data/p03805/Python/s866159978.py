N,M=map(int,input().split())
graph=[[] for _ in range(N)]
for _ in range(M):
    a,b=map(int,input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

visited=[False]*N
visited[0]=True

def dfs(v,N,visited):
    if all(visited):
        return 1
    
    ret=0
    for new_v in graph[v]:
        if visited[new_v]:
            continue
        
        visited[new_v]=True
        ret+=dfs(new_v,N,visited)
        visited[new_v]=False
    
    return ret

print(dfs(0,N,visited))