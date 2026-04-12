n,m=map(int,input().split())
G=[[0]*n for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    G[a-1][b-1]=G[b-1][a-1]=1
V=[0]*n
c=0
def dfs(v):
    global c
    if sum(V)==n:
        c+=1
        return
    for v2 in range(n):
        if G[v][v2]==1 and V[v2]==0:
            V[v2]=1
            dfs(v2)
            V[v2]=0
    return
V[0]=1
dfs(0)
print(c)