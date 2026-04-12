n, m = map(int, input().split())
G = [ set() for _ in range(n+1) ]
for  _ in range(m):
  a, b = map(int, input().split())
  G[a].add(b)
  G[b].add(a)
seen = [False]*(n+1)

def dfs(v, c):
  if c == n:
    return 1
  seen[v] = True
  temp = 0
  for nv in G[v]:
    if not seen[nv]:
      temp += dfs(nv, c+1)
  seen[v] = False
  return temp

print(dfs(1, 1))