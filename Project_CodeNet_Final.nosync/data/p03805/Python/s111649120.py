import sys
sys.setrecursionlimit(10**6)

input=sys.stdin.readline

n,m=map(int,input().split())
G=[[False]*n for _ in range(n)]
used=[False]*n

def dfs(now,depth):
    if used[now]:
        return 0
    if n==depth:
        return 1
    used[now]=True
    ans=0
    for i in range(n):
        if G[now][i]:
            ans+=dfs(i,depth+1)
    used[now]=False
    return ans

for _ in range(m):
    a,b=map(int,input().split())
    G[a-1][b-1]=True
    G[b-1][a-1]=True

print(dfs(0,1))