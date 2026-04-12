N,M=map(int,input().split())
edges=[[] for _ in range(N)]
for i in range(M):
  a,b=map(int,input().split())
  edges[a-1]+=[b-1]
  edges[b-1]+=[a-1]
vis=[1]+[0]*(N-1)#訪問フラグ

ans=0
def DFS(v):
  global ans
  if vis==[1]*N: 
    ans+=1
    return 0
  for u in edges[v]:
    if vis[u]==0:
      vis[u]=1
      DFS(u)
      vis[u]=0
  else: return 0
DFS(0)
print(ans)