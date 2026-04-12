import copy
N, M = map(int, input().split())
edges = [[] for _ in range(N+1)]


for i in range(M):
  a, b = map(int, input().split())
  edges[a].append(b)
  edges[b].append(a)

ans = 0

def dfs(u, visited):
  global ans
  stack = [u]

  while stack:
    u = stack.pop()
    visited.add(u)

    e = list(filter(lambda x: x not in visited, edges[u]))
    l = len(e)
    if l == 0:
      if len(visited) == N:
        ans += 1
    elif l == 1:
      stack.append(e[0])
    else:
      for next in e:
        dfs(next, copy.copy(visited))


dfs(1, set())
print(ans)