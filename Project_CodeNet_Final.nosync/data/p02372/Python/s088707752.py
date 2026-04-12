import sys
sys.setrecursionlimit(10**7)
def dfs(v,p):
    deg[v]=len(G[v])
    res=0
    dp[v]=[0]*deg[v]
    for i in range(deg[v]):
        nv,c=G[v][i]
        if nv==p:
            pi[v]=i
            continue
        dp[v][i]=dfs(nv,v)+c
        res=max(res,dp[v][i])

    return res
def reroot(v,res_p,p):
    if p!=-1:
        dp[v][pi[v]]=res_p
        h[v]=max(dp[v])
    dpl=[0]*(deg[v]+1)
    dpr=[0]*(deg[v]+1)
    for i in range(deg[v]):
        dpl[i+1]=max(dpl[i],dp[v][i])
    for i in reversed(range(deg[v])):
        dpr[i]=max(dpr[i+1],dp[v][i])
    for i in range(deg[v]):
        nv,c=G[v][i]
        if nv==p:
            continue
        reroot(nv,max(dpl[i],dpr[i+1])+c,v)

n=int(input())
G=[[] for i in range(n)]
dp=[[] for i in range(n)]
deg=[0]*n
pi=[-1]*n

for i in range(n-1):
    s,t,w=map(int,input().split())
    G[s].append((t,w))
    G[t].append((s,w))
z=dfs(0,-1)
h=[0]*n
h[0]=z
reroot(0,0,-1)
print(*h,sep='\n')
