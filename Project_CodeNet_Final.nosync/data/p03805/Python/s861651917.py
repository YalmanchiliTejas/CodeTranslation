def dfs(now,depth):
    if visited[now]:
        return 0
    if depth==n:
        return 1
    visited[now]=1
    ans=0
    for i in range(n):
        if connect[now][i]==1:
            ans+=dfs(i,depth+1)
    visited[now]=0
    return ans
n,m=map(int,input().split())
visited=[0]*n
edge=[[int(i)for i in input().split()]for i in range(m)]#入力値を受け取っている
connect=[[0 for i in range(n)]for i in range(n)]#隣接行列
for i in range(m):
    connect[edge[i][0]-1][edge[i][1]-1]=1
    connect[edge[i][1]-1][edge[i][0]-1]=1
print(dfs(0,1))