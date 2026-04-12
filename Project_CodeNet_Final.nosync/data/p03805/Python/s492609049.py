def dfs(v,N,visited):
  if sum(visited) == len(visited):
    return 1
  
  ret =0
  for i in range(N):
    if graph[v][i] == 0:
      continue
    if visited[i]:
      continue
    
    visited[i] = 1
    ret += dfs(i,N,visited)
    visited[i] = 0
    
  return ret


n,m = map(int,input().split())
graph = [[False]*n for _ in range(n)]

for mi in range(m):
  a,b = map(int,input().split())
  graph[a-1][b-1] = 1
  graph[b-1][a-1] = 1
  
visited = [0]*n
visited[0]= 1
print(dfs(0,n,visited))