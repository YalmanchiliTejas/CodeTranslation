import itertools

n,m = map(int, input().split())
ab = [list(map(int, input().split())) for i in range(m)]
graph = [list() for i in range(n)]
ans = 0
for a,b in ab:
  a -= 1
  b -= 1
  graph[a].append(b)
  graph[b].append(a)
for i in itertools.permutations(range(1,n)):
  now = 0
  for j in i:
    if not (j in graph[now]):
      break
    now = j
  else:
    ans += 1
print(ans)
