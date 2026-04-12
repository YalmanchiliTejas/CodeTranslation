from collections import defaultdict, deque

def dfs(graph, start_node):
  queue = deque()
  queue.append([start_node,1,[0]])
  ans = 0
  while len(queue) > 0:
    prv_node, node_num, done = queue.pop()
    for node in graph[prv_node]:
      if node not in done:
        if node_num+1 == N:ans += 1
        else:queue.append([node,node_num+1,done+[node]]) 
  return ans

N,M=map(int,input().split())
graph = defaultdict(list)

for _ in range(M):
  a,b = map(int, input().split())
  graph[a-1].append(b-1)
  graph[b-1].append(a-1)
print(dfs(graph, 0))