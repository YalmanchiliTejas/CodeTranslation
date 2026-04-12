n,m = map(int,input().split())
path = [[] for _ in range(n)]
ab = [list(map(int,input().split())) for _ in range(m)]
for a,b in ab:
  path[a-1].append(b-1)
  path[b-1].append(a-1)

def DFS(now,v_set):
  if v_set.count(True) == n:
    return 1
  if all(v_set[i] for i in path[now]):
    return 0
  c = 0
  for v in path[now]:
    if v_set[v]==False:
      v_set[v] = True
      c += DFS(v,v_set)
      v_set[v] = False
  return c
  
v_set = [False]*n
v_set[0] = True
print(DFS(0,v_set))