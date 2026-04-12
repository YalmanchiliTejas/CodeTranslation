def dfs(t):
    if 0 not in already:
        return 1
    allReach=0
    for i in range(n):
        if connect[t][i]==1 and already[i]==0:
            already[i]=1
            allReach+=dfs(i)
            already[i]=0
    return allReach

n,m=map(int,input().split())
connect=[[0 for i in range(n)]for j in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    connect[a-1][b-1]=1
    connect[b-1][a-1]=1
already=[0 for i in range(n)]
already[0]=1
print(dfs(0))
