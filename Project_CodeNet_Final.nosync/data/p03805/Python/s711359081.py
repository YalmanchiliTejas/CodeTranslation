def dfs(v,n,visited):
    all_visted=1
    for i in range(n):
        if visited[i]==0:
            all_visted=0
    if all_visted==1:
        return 1
    count=0
    for i in range(n):
        if path[v][i]==0 or visited[i]==1:
            continue
        visited[i]=1
        count+=dfs(i,n,visited)
        visited[i]=0
    return count
n,m=map(int,input().split())
path=[[0]*n for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    path[a-1][b-1]=1
    path[b-1][a-1]=1
visited=[0]*n
visited[0]=1#点1は訪問済み
print(dfs(0,n,visited))
