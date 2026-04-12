def dfs(n,depth):
    if used[n]:
        return 0
    if depth==N:
        return 1
    used[n]=1
    ans=0
    for i in range(N):
        if connect[n][i]:
            ans+=dfs(i,depth+1)
    used[n]=0
    return ans

N,M=map(int,input().split())
used=[0]*N
connect=[[0 for i in range(N)]for j in range(N)]
a=[];b=[]

for i in range(M):
    x,y=map(int,input().split())
    a.append(x-1)
    b.append(y-1)

for i in range(M):
    connect[a[i]][b[i]]=connect[b[i]][a[i]]=1

print(dfs(0,1))