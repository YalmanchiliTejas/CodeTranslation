from collections import defaultdict
n, m = list(map(int, input().split()))
edge = defaultdict(list)
for i in range(m):
  a, b = list(map(int, input().split()))
  edge[a-1].append(b-1)
  edge[b-1].append(a-1)
visited = [0 for i in range(n)]
ans = 0

def dfs(x, t):
  if t==n:
    return 1

  visited[x] = 1
  cur = 0
  for nx in edge[x]:
    if not visited[nx]:
      cur += dfs(nx, t+1)
  visited[x] = 0
  return cur

print(dfs(0, 1))