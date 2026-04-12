N,M = tuple(map(int,input().split()))
from collections import defaultdict
graph = defaultdict(list)
for i in range(M):
  a,b = tuple(map(int,input().split()))
  graph[a].append(b)
  graph[b].append(a)
  
# pathを運んで，その中で
queue = [(1,set())]
res = 0
while queue:
  now,prevs = queue.pop()
  
  if len(prevs) == N-1:
      res += 1
      continue
  for next_node in graph[now]:
    #print("{}: {}->{} {}".format(prevs,now,next_node,"o" if next_node not in prevs else "x"))
    if next_node not in prevs:
      queue.append((next_node, prevs|{now}))
print(res)