n,m=list(map(int,input().split()))

edge=[[] for i in range(n)]

for i in range(m):
    a,b=list(map(int,input().split()))
    a-=1
    b-=1
    edge[a].append(b)
    edge[b].append(a)

ans=0
def search(his,nxt):
    global ans
    newhis=his.copy()
    newhis.append(nxt)
    if len(newhis)==n:
        ans+=1
        return
    for i in edge[nxt]:
        if i in newhis:continue
        search(newhis,i)




search([],0)

print(ans)