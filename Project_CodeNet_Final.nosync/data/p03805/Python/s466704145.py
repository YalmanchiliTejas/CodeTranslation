def dfs(v, n, visited):
  passed = True
  for i in range(n):
    if not visited[i]:
      passed = False
  if passed:
    return 1
  ret = 0
  for i in range(n):
    if (v, i) not in graph:
      continue
    if not graph[(v, i)]:
      continue
    if visited[i]:
      continue
    visited[i] = True
    ret += dfs(i, n, visited)
    visited[i] = False
  return ret

n, m = map(int, input().split())
graph = {}
for _ in range(m):
  a, b = map(int, input().split())
  graph[(a-1,b-1)] = True
  graph[(b-1,a-1)] = True
visited= [False] *n
visited[0] = True
print(dfs(0, n, visited))