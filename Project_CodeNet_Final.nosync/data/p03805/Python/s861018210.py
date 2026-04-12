import itertools

n,m=map(int,input().split())
path={i+1:[] for i in range(n)}
for i in range(m):
    u,v=map(int,input().split())
    path[u].append(v)
    path[v].append(u)
chk=[i for i in range(2,n+1)]
ans=0
for way in list(itertools.permutations(chk)):
    now=1
    if way[0] in path[now]:
        f=1
        for j in way:
            if j in path[now]:
                now=j
                f+=1
            else:
                break
        if f==n: ans+=1
print(ans)