N, M = map(int, input().split())
graph = [[False for i in range(N)] for j in range(N)]
visit = [False for i in range(N)]
for i in range(M):
  a, b = map(lambda x: int(x) - 1, input().split())
  graph[a][b] = graph[b][a] = True
visit[0] = True

def dfs(c, n, vis):
  for i in range(n):
    if not vis[i]:
      break
  else:
    return 1
  ret = 0
  for i in range(n):
    if not graph[c][i]:
      continue
    if vis[i]:
      continue
    vis[i] = True
    ret += dfs(i, n, vis)
    vis[i] = False
  return ret

print(dfs(0, N, visit))