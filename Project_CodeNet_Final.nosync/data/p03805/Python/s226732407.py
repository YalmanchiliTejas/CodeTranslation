def dfs(now,depth):
    if vis[now]:
        return 0
    if depth==n:
        return 1
    vis[now]=1
    ans=0
    for i in range(n):
        if graph[now][i]:
            ans+=dfs(i,depth+1)
    vis[now]=0
    return ans
n,m=map(int,input().split())
edge=[[int(i)for i in input().split()]for i in range(m)]
graph=[[0 for i in range(n)] for i in range(n)]
vis=[0]*n
for i in range(m):
    graph[edge[i][0]-1][edge[i][1]-1]=1
    graph[edge[i][1]-1][edge[i][0]-1]=1
print(dfs(0,1))
