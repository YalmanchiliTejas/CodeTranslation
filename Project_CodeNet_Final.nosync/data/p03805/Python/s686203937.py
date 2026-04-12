import sys
import collections
INF = 10**18
ans = 0

def dfs2(now,edge,l,cnt):
    global ans
    if len(l) == n:
        ans+=1
        return
    visited[now] = True
    for v in edge[now]:
        if visited[v] == False:
            l.append(v)
            dfs2(v,edge,l,cnt)
            l.pop()
            visited[v] = False

if __name__ == "__main__":
    n,m = map(int,input().split())
    edge =[[] for i in range(n)]
    for i in range(m):
        a,b = map(int,input().split())
        a-=1
        b-=1
        edge[a].append(b)
        edge[b].append(a)
    l = [0]
    visited = [False]*(n)
    dfs2(0,edge,l,0)
    print(ans)