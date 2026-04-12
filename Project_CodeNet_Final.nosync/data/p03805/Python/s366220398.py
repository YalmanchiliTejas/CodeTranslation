from itertools import permutations
from copy import deepcopy

N,M = [int(i) for i in input().split()]
links  = [[int(i) for i in input().split()] for _ in range(M)]

ans = 0

for path in permutations(range(2,N+1)):
    l = deepcopy(links)
    p_node = 1
    for n_node in path:
        if sorted([p_node,n_node]) in l:
            l.pop(l.index(sorted([p_node,n_node])))
            p_node = n_node
            continue
        else:
            break
    else:
        ans += 1 
print(ans)   
