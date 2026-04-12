N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(M)]
 
graph_ex = [[0 for _ in range(N)] for _ in range(N)]
for i in graph:
  graph_ex[i[0]-1][i[1]-1] = 1
  graph_ex[i[1]-1][i[0]-1] = 1

al_vis = [False for _ in range(N)]
al_vis[0] = True
def dfs(v, visited, cnt):
  if cnt == N-1:
    return 1
  ret = 0
  for i in range(N):
    if graph_ex[v][i] == 1 and visited[i] == False:
      visited[i] = True
      ret += dfs(i, visited, cnt+1)
      visited[i] = False
  return ret
ret = dfs(0, al_vis, 0)
print(ret)