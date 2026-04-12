import numpy as np
N, M = map(int, input().split())
 
G = np.zeros((N, N)) 
total_path_num = 0
not_reach_node = list(range(1, N))
node = 0
 
for i in range(M):
  a, b = map(int, input().split())
  G[a-1, b-1] += 1
  G[b-1, a-1] += 1
  
def search_path(G, not_reach_node, node):
  global total_path_num
  if len(not_reach_node) == 0:
    total_path_num += 1
    return total_path_num
  
  for x in np.where((G[node] == 1))[0]:
    if (x in not_reach_node):
      not_reach_node_copy = not_reach_node.copy()
      not_reach_node_copy.remove(x)
      search_path(G, not_reach_node_copy, x)

search_path(G, not_reach_node, node)      	
 
print(total_path_num)