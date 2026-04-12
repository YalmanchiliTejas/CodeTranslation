n,m=map(int,input().split())
paths=[]

for i in range(n):
    paths.append([0]*n)

for i in range(m):
    a,b=map(int,input().split())
    paths[a-1][b-1]=1
    paths[b-1][a-1]=1
visited=[0]*n

def dfs(now,depth):
    if visited[now]==1:
        return 0
    elif depth==n-1:
        return 1
    else:
        visited[now]=1
        total=0
        for i in range(n):
            if paths[now][i]==1:
                total+=dfs(i,depth+1)
        visited[now]=0
        return total
print(dfs(0,0))