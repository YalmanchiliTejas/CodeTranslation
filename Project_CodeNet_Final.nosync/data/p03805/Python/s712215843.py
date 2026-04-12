N,M=map(int,input().split())
edges=[[] for _ in range(N)]
for i in range(M):
  a,b=map(int,input().split())
  edges[a-1]+=[b-1]
  edges[b-1]+=[a-1]
vis=[1]+[0]*(N-1)#訪問フラグ

def DFS(v):
  if vis==[1]*N: 
    return 1
  ret=0
  for u in edges[v]:
    if vis[u]==0:
      vis[u]=1
      ret+=DFS(u)
      vis[u]=0
  else: return ret
print(DFS(0))