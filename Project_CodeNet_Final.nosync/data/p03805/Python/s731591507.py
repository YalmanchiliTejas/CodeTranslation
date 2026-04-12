N, M = map(int,input().split())

def dfs(edge, reach):
  if(all(reach)):
    return 1
  ret = 0
  for e in edges[edge]:
    if(reach[e]):
      continue
    reach[e] = True
    ret += dfs(e, reach)
    reach[e] = False
  return ret

edges = [[] for _ in range(N)]
all_reach = [False for _ in range(N)]

for _ in range(M):
  a, b = map(int,input().split())
  a -= 1
  b -= 1
  edges[a] = edges[a] + [b]
  edges[b] = edges[b] + [a]

all_reach[0] = True
print(dfs(0, all_reach))