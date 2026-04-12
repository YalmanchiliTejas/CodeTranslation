n,m=map(int,input().split())
edges=[[0]*n for i in range(n)]
for i in range(m):
  a,b=map(int,input().split())
  edges[a-1].append(b-1)
  edges[b-1].append(a-1)

visited=[False]*n
count=0
def dfs(u,visited):
  global count
  visited=visited[:]
  visited[u]=True
  if all(visited):
    count+=1
    return
  for v in edges[u]:
    if not visited[v]:
      dfs(v,visited)
  return False

dfs(0,visited)
print(count)