def search(node, searched, goal):
  if searched == goal:
    return 1
  v = 0
  for nei in edges[node]:
    if searched & (1 << nei):
      continue
    v += search(nei, searched | (1<<nei), goal)
    
  return v

n, m = map(int, input().split())
edges = [[] for _ in range(n)]
for i in range(m):
  a, b = map(lambda x: int(x) - 1, input().split())
  edges[a].append(b)
  edges[b].append(a)
print(search(0, 1, (1<<n) - 1))
