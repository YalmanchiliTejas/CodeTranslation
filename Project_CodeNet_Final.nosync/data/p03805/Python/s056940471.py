n, m = map(int, input().split())
link = [[] for _ in range(n)]
for i in range(m):
    tmp = list(map(int,input().split()))
    link[tmp[0]-1].append(tmp[1]-1)
    link[tmp[1]-1].append(tmp[0]-1)
lis = list(range(1,n))
ans=0
from itertools import *
for perm in list(permutations(lis)):
    last=0
    ok=1
    for i in range(len(perm)):
        if perm[i] not in link[last]:
            ok=0
        last=perm[i]
    ans+=ok
print(ans)