n,m = map(int,input().split())
graph = [[]for i in range(n)]


for i in range(m):
    a,b = map(int,input().split())
    a -=1
    b-=1
    graph[a].append(b)
    graph[b].append(a)
def all_visited(l):
    a = 0
    for i in range(n):
        if l[i]:
            a+=1
    if a == n:
        return 1
    else: return 0
def dfs(now):

    ans = 0
    visited[now] = 1
  
    if all_visited(visited):
        
        return 1
    for next in graph[now]:
        if visited[next]:continue
        ans += dfs(next)
        visited[next] =0
    return ans
visited = [0]*n
print(dfs(0))