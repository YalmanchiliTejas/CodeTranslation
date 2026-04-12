N, M = map(int, raw_input().split())
neighbor_graph = [[False] * N for _ in range(N)]
for _ in range(M):
  a, b = map(int, raw_input().split())
  neighbor_graph[a - 1][b - 1] = True
  neighbor_graph[b - 1][a - 1] = True

def find(now, checked):
  if len(checked) == N:
    return 1
  res = 0
  for i in set(range(N)) - checked:
    if neighbor_graph[now][i]:
      res += find(i, checked | {i})
  return res

print find(0, {0})