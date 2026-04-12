n,m=map(int,input().split())
l=[]
for i in  range(m):
    a=[int(i) for i in input().split()]
    l.append(a)

ans=[]
li=[0 for i in range(n+1)]

def dfs(a,r):
    r[a]=1
    p=0
    q=0
    for i in range(m):
        if l[i][0]==a or l[i][1]==a:
            q+=1
            b=l[i][0]*l[i][1]//a
            if r[b]==0:
                dfs(b,r)
                r[b]=0
            else:
                p+=1
    if p==q and sum(r)==n:
        ans.append(1)

dfs(1,li)
print(sum(ans))
        




