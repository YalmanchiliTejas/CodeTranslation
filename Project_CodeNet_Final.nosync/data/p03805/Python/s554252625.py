n,m=map(int,input().split())
edges=[[] for _ in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    edges[a-1]+=[b-1]
    edges[b-1]+=[a-1]
vis=[1]+[0]*(n-1)

def dfs(v):
    if vis==[1]*n:
        return 1
    count=0
    for i in edges[v]:
        if vis[i]==0:
            vis[i]=1
            count+=dfs(i)
            vis[i]=0
    else:
        return count
print(dfs(0))
