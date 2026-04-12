import itertools
n,m=map(int,input().split())
graph=[[False for h in range(n)] for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    a-=1;b-=1
    graph[a][b]=True
    graph[b][a]=True
l=[i for i in range(1,n)]
ans=0
if n==2:
    print(m)
    exit()
for v in itertools.permutations(l):
    flag=1
    if graph[0][v[0]]==False:continue
    else:
        c=v[0]
        for j in v[1:]:
            if graph[c][j]==False:
                flag=0
                break
            c=j
        ans+=flag
print(ans)
