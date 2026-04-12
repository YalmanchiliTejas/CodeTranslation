n, m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
  a, b = map(int, input().split())
  g[a - 1].append(b - 1)
  g[b - 1].append(a - 1)

def go(curr, used, count):
  if count == 1:
    return 1
  tmp = used + [curr]
  return sum(go(node, tmp, count - 1) for node in g[curr] if node not in used)

print(go(0, [], n))