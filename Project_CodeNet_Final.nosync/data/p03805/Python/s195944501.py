N, M = map(int, input().split())
G = [[] for i in range(N)]
for i in range(M):
  a, b = map(int, input().split())
  G[a - 1].append(b - 1)
  G[b - 1].append(a - 1)
def dfs(V, v):
  _V = [v for v in V]
  _V[v] = 1
  cnt = 0
  if sum(_V) == N:
    return 1
  else:
    for adj in G[v]:
      if _V[adj] == 0:
        cnt += dfs(_V, adj)
    return cnt
print(dfs([0] * N, 0))