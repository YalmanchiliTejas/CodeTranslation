N, M = map(int, input().split())
distinations = [[] for _ in range(N+1)]
for _ in range(M):
  _to, _from = map(int, input().split())
  distinations[_to].append(_from)
  distinations[_from].append(_to)
firsts = distinations[1]
stack = []
for _first in firsts:
  stack.append((_first, 1))
cnt = 1
ans = 0
path = [1]
while len(stack) > 0:
  dist = stack.pop()
  path = path[:dist[1]]
  if dist[0] in path:
    continue
  path += [dist[0]]
  cnt = dist[1] + 1
  if cnt == N:
    ans += 1
    continue
  for node in distinations[dist[0]]:
    stack.append((node, cnt))
print(ans)
