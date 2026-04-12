def dfs(v,visited):
  if all(visited):
    return 1
  res=0
  for nv in G[v]:
    if visited[nv]:
      continue
    visited[nv]=1
    res+=dfs(nv,visited)
    visited[nv]=0
  return res
 
n,m=map(int, input().split())
G=[[] for _ in range(n)]
visited=[0]*n
res=0
 
for i in range(m):
  a,b=map(int, input().split())
  G[a-1].append(b-1)
  G[b-1].append(a-1)

visited[0]=1
print(dfs(0,visited))