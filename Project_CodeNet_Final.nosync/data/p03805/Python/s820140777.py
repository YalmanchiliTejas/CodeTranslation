import itertools

n,m=map(int,input().split())
g=[list(map(int,input().split())) for _ in range(m)]
v=list(itertools.permutations(range(1,n+1)))

ans=0

for x in v:
    tf=True
    if x[0]!=1:
        tf=False
    else:
        for i in range(n-1):
            if not ([x[i],x[i+1]] in g or [x[i+1],x[i]] in g):
                tf=False
                break
    if tf:
        ans+=1
print(ans)