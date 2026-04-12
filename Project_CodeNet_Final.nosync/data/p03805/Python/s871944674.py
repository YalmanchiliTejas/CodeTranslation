N, M = list(map(int, input().split()))

g = [[] for _ in range(N)]

for i in range(M):
  a, b = list(map(int, input().split()))
  g[a-1].append(b-1)
  g[b-1].append(a-1)

visited = [False for _ in range(N)]

def dfs(v, visited):
  if all(visited):
    return 1
  total = 0
  for cv in g[v]:
    if not visited[cv]:
      visited[cv] = True
      total += dfs(cv, visited)
      visited[cv] = False
  return total
    
visited[0] = True
ret = dfs(0, visited)
print(ret)