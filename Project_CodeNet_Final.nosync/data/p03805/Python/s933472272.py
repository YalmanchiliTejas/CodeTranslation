def dfs():
  stack = [[0]]
  count = 0
  while stack:
    route = stack.pop()
    if len(route) == N:
      #print 'route=',route
      count += 1
      continue
    now = route[-1]
    for next in filter(lambda x: EDGES[now][x] == 1, range(N)):
      #print 'now,next',now,next
      if next in route:
        continue
      newroute = route[:]
      newroute.append(next)
      stack.append(newroute)
  return count

N,M = map(int, raw_input().split())
EDGES = [[0 for i in range(N)] for i in range(N)]
for i in range(M):
  a,b = map(int, raw_input().split())
  EDGES[a-1][b-1] = 1
  EDGES[b-1][a-1] = 1

print dfs()