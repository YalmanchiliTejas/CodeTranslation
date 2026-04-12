from itertools import permutations
from copy import deepcopy

N,M = [int(i) for i in input().split()]
links  = set([input().strip() for _ in range(M)])

ans = 0

for path in permutations(range(2,N+1)):
    l = deepcopy(links)
    p_node = 1
    for n_node in path:
        e_l = " ".join([str(s) for s in sorted([p_node,n_node])])
        if e_l in l:
            l.remove(e_l)
            p_node = n_node
            continue
        else:
            break
    else:
        ans += 1 

print(ans)