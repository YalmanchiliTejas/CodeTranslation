def dp(d,i):
    if sum(d)==n-1:return 1
    x=0
    for j in l[i]:
        if d[j-2]==1:continue
        di=d[:]
        di[j-2]=1
        x+=dp(di,j)
    return x
        
n,m=map(int,input().split())
l=[[] for _ in range(n+1)]
for i in range(m):
    a,b=map(int,input().split())
    if b!=1:l[a].append(b)
    if a!=1:l[b].append(a)
print(dp([0]*(n-1),1))