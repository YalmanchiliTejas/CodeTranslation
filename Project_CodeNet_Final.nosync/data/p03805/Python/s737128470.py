def dfs(now,depth):
    if use[now]:
        return 0

    if depth==n:
        return 1

    use[now]=1
    ans=0

    for i in range(n):
        if gragh[now][i]:
            ans+=dfs(i,depth+1)

    use[now]=0
    return ans

n,m=map(int,input().split())
gragh=[[0]*n for _ in range(n)]

for i in range(m):
    a,b=map(int,input().split())
    gragh[a-1][b-1]=gragh[b-1][a-1]=1

use=[0]*n

print(dfs(0,1))