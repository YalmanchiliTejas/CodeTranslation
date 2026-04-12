N,M = map(int,input().split())
E = [set() for _ in range(N)]
for i in range(M):
  a,b = map(int,input().split())
  a -= 1
  b -= 1
  E[a].add(b)
  E[b].add(a)
#print(E)

def dfs(v,c):
  if c == N:
    return 1
  res = 0
  for u in E[v]:
    if not visited[u]:
      visited[u] = True
      res += dfs(u,c+1)
      visited[u] = False
  return res

visited = [True] + [False for _ in range(N-1)]
print(dfs(0,1))