import sys 

sys.setrecursionlimit(10**6)

N, M = map(int, input().split())
G = [list(map(int, input().split())) for _ in range(M)]
visited = [True if v == 0 else False for v in range(N)]
adj = {i+1:[] for i in range(N)}

# init
for g in G:
  adj[g[0]].append(g[1])
  adj[g[1]].append(g[0])
  
def dfs(adj, visited, x):
  if all(visited):
    return 1
  count = 0
  for v in adj[x]:
    if visited[v-1]:
      continue
    visited[v-1] = True
    count += dfs(adj, visited, v)
    visited[v-1] = False
  return count

print(dfs(adj, visited, 1))