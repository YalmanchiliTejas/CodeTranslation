import itertools

N, M = map(int, input().split())
graph = [[] for i in range(N)]
for i in range(M):
  a, b = map(int, input().split())
  a -= 1; b -= 1
  graph[a].append(b); graph[b].append(a)

path = list(itertools.permutations(range(1, N), N-1))
ans = 0
for p in path:
  now = 0
  res = True
  for child in p:
    if child not in graph[now]:
      res = False
      break
    now = child
  ans += res

print(ans)