import sys

sys.setrecursionlimit(10**8)
n,m = map(int,input().split())
graph = [[]for i in range(n)]
visited = [0]*n
def all_v(visited):
    cnt = 0
    for x in visited:cnt+=x
    return cnt == n
def dfs(now):
    visited[now] = 1
    if all_v(visited):return 1
    res = 0
    for next in graph[now]:
        if visited[next]:continue
        res += dfs(next)
        visited[next] = 0
    return res
    
for i in range(m):
    a,b = map(int,input().split())
    a-=1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)
print(dfs(0))
