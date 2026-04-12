def dfs(v,n,visited):
    all_visted=True
    for i in range(n):
        if visited[i]==False:
            all_visted=False
    if all_visted==True:
        return 1
    ret=0
    for i in range(n):
        if path[v][i]==False:
            continue
        if visited[i]==True:
            continue
        visited[i]=True
        ret+=dfs(i,n,visited)
        visited[i]=False
    return ret
n,m=map(int,input().split())
path=[[False]*n for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    path[a-1][b-1]=True
    path[b-1][a-1]=True
visited=[False]*n
visited[0]=True
print(dfs(0,n,visited))
