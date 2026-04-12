from itertools import permutations as p
from collections import defaultdict as dd

n,m=map(int,input().split())
d=dd(list)
for _ in range(m):
    a,b=map(int,input().split())
    d[a].append(b)
    d[b].append(a)
d=dict(d)
ans=0

for i in p(range(2,n+1)):
    pos=1
    for j in i:
        if not j in d[pos]:
            break
        pos=j
    else:
        ans+=1

print(ans)