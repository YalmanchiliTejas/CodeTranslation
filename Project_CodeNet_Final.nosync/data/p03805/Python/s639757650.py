import itertools
from collections import deque

n, m = map(int,input().split())
edge = [[] for _ in range(n)]
for _ in range(m):
    a,b = map(int,input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)
    
ans = 0
for p in itertools.permutations([i+1 for i in range(n-1)]):
    pp = [0]+list(p)
    #print('pp',pp)
    now = pp[0]
    for i in range(1,n):
        if pp[i] in edge[now]:
            now = pp[i]
        else:
            break
    else:
        ans += 1
    
print(ans)