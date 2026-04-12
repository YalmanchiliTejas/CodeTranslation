from collections import deque

N,M = map(int,input().split())

G=[[] for i in range(N+1)]

for i in range(M):
    n,m=map(int,input().split())
    G[n].append(m)
    G[m].append(n)

visited=[0]*(N+1)
ans=0
def dfs(now, num_visited=0):
    global ans
    visited[now] = 1
    num_visited+=1
    
    if num_visited==N:
        ans+=1
    
    for i in G[now]:
        next=i
        if visited[next]!=1:dfs(next,num_visited)

    visited[now] = 0

dfs(1)
print(ans)