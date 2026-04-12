import sys
sys.setrecursionlimit(2147483647)
INF=float("inf")
MOD=10**9+7
input=lambda :sys.stdin.readline().rstrip()
def resolve():
    n,m=map(int,input().split())
    E=[[] for _ in range(n)]
    for _ in range(m):
        a,b=map(lambda x:int(x)-1,input().split())
        E[a].append(b)
        E[b].append(a)
    def dfs(v,vis):
        vis[v]=1
        if all(vis): return 1
        res=0
        for u in E[v]:
            if vis[u]==0:
                nvis=vis[:]
                res+=dfs(u,nvis)
        return res
    print(dfs(0,[0]*n))
resolve()