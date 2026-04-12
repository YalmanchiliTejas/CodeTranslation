N, M = map(int, input().split())
G = [[] for _ in range(N)]
visited = [False]*N
visited_all = [True]*N
for i in range(M):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  G[a].append(b)
  G[b].append(a)
ans = [0]
  
def dfs(node):
  visited[node] = True
  if visited == visited_all:
    ans[0] += 1
  else:
    for i in range(len(G[node])):
      next_node = G[node][i]
      if visited[next_node] == True:
        continue
      dfs(next_node)
      visited[next_node] = False

dfs(0)
print(ans[0])