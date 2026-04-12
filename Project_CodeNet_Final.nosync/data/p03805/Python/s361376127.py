n,m=map(int,input().split())
a=[None]*m
b=[None]*m
edge=[[] for _ in range(n)]
for i in range(m):
  a0,b0=map(int,input().split())
  a[i]=a0-1
  b[i]=b0-1
  edge[a0-1]+=[b0-1]
  edge[b0-1]+=[a0-1]

def dfs(v,nodes):
  u_nodes=nodes[:]
  if v not in u_nodes:
    return 0
  u_nodes.remove(v)
  if len(set(u_nodes) & set(edge[v]))==0:
    return 0
  if len(u_nodes)==1:
    return 1
  ret=0
  for i in set(u_nodes) & set(edge[v]):
    ret+=dfs(i,u_nodes)
  return ret

nodes=[i for i in range(n)]
print(dfs(0,nodes))