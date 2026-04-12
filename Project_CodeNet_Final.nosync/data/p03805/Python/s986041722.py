N,M=map(int,input().split())
G=[[False]*N for i in range(N)]
for i in range(M):
  a,b=map(int,input().split())
  G[a-1][b-1]=G[b-1][a-1]=True
V=[False]*N
V[0]=True

def dfs(v):
  if not False in V: return 1
  ret=0
  for i in range(N):
    if not G[v][i]: continue
    if V[i]: continue
    V[i]=True
    ret+=dfs(i)
    V[i]=False
  return ret

print(dfs(0))
