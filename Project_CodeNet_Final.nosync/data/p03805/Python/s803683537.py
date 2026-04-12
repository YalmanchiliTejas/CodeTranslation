def bfs(u):
  if used.count(True) == N:
    res[0] += 1
    return
  for v in adj[u]:
    if used[v]:
      continue
    used[v] = True
    bfs(v)
    used[v] = False

N, M = map(int, input().split())
adj = [[] for i in range(N)]
for i in range(M):
  u, v = map(lambda x: int(x)-1, input().split())
  adj[u].append(v)
  adj[v].append(u)

used = [False for i in range(N)]
used[0] = True
res = [0]
bfs(0)

print(res[0])
