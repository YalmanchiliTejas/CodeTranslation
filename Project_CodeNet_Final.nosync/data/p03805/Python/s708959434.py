N, M  = map(int,input().strip().split())
edges = [[x for x in  map(int,input().strip().split())] for i in range(M)]
import numpy as np
a = np.zeros([N+1,N+1],dtype = np.int32) # adjacency matrix
for e in edges:
    a[e[0],e[1]] = 1
a = a.T+a
def iter(visited_nodes):
    if len(visited_nodes) == N:
        return 1
    else:
        now = visited_nodes[-1] 
        return sum(iter(visited_nodes+[node]) for node, aij in enumerate(a[now]) if aij == 1 and not (node in visited_nodes))
print(iter([1]))

