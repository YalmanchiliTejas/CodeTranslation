n,m=map(int,input().split())
g=[[] for _ in range(n)]
for _ in range(m):
    a,b=map(int,input().split())
    a,b=a-1,b-1
    g[a].append(b)
    g[b].append(a)

ed=[0]*n
ed[0]=1
ans=[0]*n

def f(x):
    if 0 not in ed:
        ans[x]+=1
        return
    for a in g[x]:
        if ed[a]==0:
            ed[a]=1
            f(a)
            ed[a]=0
f(0)
print(sum(ans))
