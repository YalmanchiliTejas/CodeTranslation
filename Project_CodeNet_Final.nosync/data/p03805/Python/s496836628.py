n,m=map(int,input().split())
es=[[] for _ in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    es[a-1].append(b-1)
    es[b-1].append(a-1)

from itertools import permutations
perm=permutations(range(1,n))
ans=0
for p in perm:
    newp=[0]+list(p)
    flg=True
    for i in range(n-1):
        if newp[i+1] not in es[newp[i]]:
            flg=False
            break
    if flg: ans+=1
print(ans)