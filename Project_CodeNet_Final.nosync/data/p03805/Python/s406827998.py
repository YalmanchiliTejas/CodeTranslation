N,M = map(int, input().strip().split(' '))
graph_dict = {}
for _ in range(M):
  a,b = map(int, input().strip().split(' '))
  if a in graph_dict:
    graph_dict[a].add(b)
  else:
    graph_dict[a] = {b}
  if b in graph_dict:
    graph_dict[b].add(a)
  else:
    graph_dict[b] = {a}

def search(now, visited):
  #print(now, visited)
  if len(visited)+1 == N:
    return 1
  if len(graph_dict[now]-visited) == 0:
    return 0
  return sum(search(n, visited|{now}) for n in graph_dict[now]-visited)
  

print(search(1, set()))