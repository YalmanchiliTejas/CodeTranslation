from collections import deque

def dfs(corrent, cnt):
  if cnt == N-1:
    return 1
  visited[corrent] = True
  ret = 0
  for to in graph[corrent]:
    if visited[to] == True:
      continue
    ret += dfs(to, cnt+1)
  visited[corrent] = False
  return ret


N, M = map(int, input().split())
graph = [[] for _ in range(N)]

ans = 0
visited = [False]*(N)

for _ in range(M):
  x, y = map(int, input().split())
  x -= 1
  y -= 1
  graph[x].append(y)
  graph[y].append(x)

print(dfs(0, 0))