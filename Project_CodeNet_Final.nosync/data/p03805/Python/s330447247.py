import itertools

n, m = map(int, input().split())
g = []
for i in range(n+1):
  g.append([])

for i in range(m):
  a, b = map(int, input().split())
  g[a].append(b)
  g[b].append(a)

t = [num for num in range(1, n+1)]
ans = 0
for per in itertools.permutations(t):
  if per[0] != 1:
    continue
  for i in range(n-1):
    start = per[i]
    end = per[i+1]
    if not end in g[start]:
      break
  else:
    ans += 1
print(ans)