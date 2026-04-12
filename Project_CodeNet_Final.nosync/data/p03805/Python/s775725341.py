import itertools
n,m=map(int,input().split())
es=[set() for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    es[a-1].add(b-1)
    es[b-1].add(a-1)
ans=0
for v in itertools.permutations(range(1,n)):
    u=0
    link=True
    for i in v:
        if i in es[u]:
            u=i
        else:
            link=False
            break
    if link:
        ans+=1
print(ans)