n,m=map(int,input().split())
def dfs(now,depth):
    if used[now]:
        return 0
    if depth==n:
        return 1
    used[now]=1
    ans=0
    for i in range(n):
        if connect[now][i]:
            ans+=dfs(i,depth+1)
    used[now]=0
    return ans
edge=[[int(i)for i in input().split()]for i in range(m)]#入力値受け取り、グラフの初期設定
connect=[[0 for i in range(n)]for i in range(n)]
for i in range(m):
    connect[edge[i][0]-1][edge[i][1]-1]=1
    connect[edge[i][1]-1][edge[i][0]-1]=1
used=[0]*n
print(dfs(0,1))

