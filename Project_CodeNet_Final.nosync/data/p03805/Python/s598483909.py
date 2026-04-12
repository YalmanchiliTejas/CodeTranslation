n,m=map(int,input().split())
a=[0]*m;b=[0]*m
for i in range(m):a[i],b[i]=map(int,input().split())
r=[False]*n
r[0]=True
c=0
def sol(x):
    global c
    if all(r):c+=1;
    else:
        for i in range(m):
            if a[i]==x and r[b[i]-1]==False:
                r[b[i]-1]=True
                sol(b[i])
                r[b[i]-1]=False
            if b[i]==x and r[a[i]-1]==False:
                r[a[i]-1]=True
                sol(a[i])
                r[a[i]-1]=False
sol(1)
print(c)