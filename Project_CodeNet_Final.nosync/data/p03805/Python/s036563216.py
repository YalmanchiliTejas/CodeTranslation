# https://img.atcoder.jp/abc054/editorial.pdf

N, M = map(int, input().split())

graph = [[False for _ in range(N)] for i in range(N)]
for i in range(M):
  a, b = map(int, input().split())
  graph[a-1][b-1] = graph[b-1][a-1] = True

def dfs(v, visited):
  all_visited = True
  for i in range(N):
    if not visited[i]:
      all_visited = False
      
  if all_visited:
    return 1
  
  ret = 0
  for i in range(N):
    if not graph[v][i]: continue
    if visited[i]: continue
    
    visited[i] = True
    ret += dfs(i, visited)
    visited[i] = False
  
  return ret

visited = [False] * N
visited[0] = True
ans = dfs(0, visited)
print(ans)
