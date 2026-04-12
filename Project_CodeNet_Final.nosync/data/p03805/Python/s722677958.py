from itertools import permutations

n, m = map(int, input().split())
G = [set() for _ in range(n)]
for _ in range(m):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  G[a].add(b)
  G[b].add(a)
ans = 0
for l in permutations(range(n)):
  if l[0] != 0:
    continue
  for i in range(n-1):
    if l[i+1] not in G[l[i]]:
      break
  else:
    ans += 1
print(ans)