n,X,m=map(int,input().split())
if m==1:
    print(0)
else:
    x=[0]*m
    y=[0]*m
    y[0]=X
    z=[0]*(m+1)
    z[X]+=1
    for i in range(1,m):
        x[i]=(i**2)%m
    for i in range(1,m):
        y[i]=x[y[i-1]]
        z[y[i]]+=1
        if z[y[i]]==2:
            e=i
            q=y[i]
            break
    for i in range(len(y)):
        if y[i]==q:
            b=i
            break
    l=y[b:e]
    L=len(l)
    s=sum(l)
    #print(x)
    #print(y)
    #print(z)
    #print(b,e)
    #print(l)
    #print(sum(y[:b]))
    #print(((n-b)//L)*s)
    #print(sum(l[:(n-b)%L]))
    if n>=b:
        ans=sum(y[:b])+((n-b)//L)*s+sum(l[:(n-b)%L])
    else:
        ans=sum(y[:n])
    print(ans)