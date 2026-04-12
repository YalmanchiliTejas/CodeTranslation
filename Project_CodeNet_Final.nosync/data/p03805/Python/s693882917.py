def dfs(v,n,visited):
    all_visted=1
    for i in range(n):
        if visited[i]==0:
            all_visted=0
    if all_visted==1:
        return 1
    ret=0
    for i in range(n):
        if path[v][i]==0:
            continue
        if visited[i]==1:
            continue
        visited[i]=1
        ret+=dfs(i,n,visited)
        visited[i]=0
    return ret
n,m=map(int,input().split())
path=[[0]*n for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    path[a-1][b-1]=1
    path[b-1][a-1]=1
visited=[0]*n
visited[0]=1
print(dfs(0,n,visited))
