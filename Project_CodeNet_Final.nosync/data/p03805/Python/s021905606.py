n,m=map(int,input().split())
G=[[] for _ in range(1+n)]
for i in range(m):
    a,b=map(int,input().split())
    G[a].append(b)
    G[b].append(a)

from itertools import permutations
lis=[i for i in range(2,n+1)]
permu=list(permutations(lis))

ans=0
for pl in permu:
    c=1
    j=1
    for i in pl:
        if j in G[i]:
            j=i
        else:
            c=0
            break
    ans+=c
print(ans)