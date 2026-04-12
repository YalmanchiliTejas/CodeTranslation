ans = 0
def dfs(v, visiteNode, graph):
  visiteNode[v] = 1
  if all(visiteNode):
    global ans
    ans += 1
    return
  for node in graph[v]:
    if visiteNode[node]:
      continue
    else:
      dfs(node, visiteNode[:], graph)

N,M = map(int, input().split())
v = 0
visiteNode = [0] * N

graph = [[] for _ in range(N)]
for _ in range(M):
  a,b = map(int, input().split())
  a -= 1
  b -= 1
  graph[a].append(b)
  graph[b].append(a)
  
dfs(v, visiteNode, graph)
print(ans)