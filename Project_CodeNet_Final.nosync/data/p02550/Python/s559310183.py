n,x,m=map(int,input().split())
if n<=m+1:
    s=0
    a=x
    for c in range(n):
        s+=a
        a=pow(a,2,m)
else:
    l=[0]*m
    a=x
    l[a]=1
    for c in range(2,m+2):
        a=pow(a,2,m)
        if l[a]>0:
            d1=l[a]
            d2=c
            d3=a
            break
        l[a]=c
    q=(n-d1)//(d2-d1)
    r=(n-d1)%(d2-d1)+d1
    s=0
    for c in range(d2-d1):
        s+=a
        a=pow(a,2,m)
    s*=q
    for c in range(r):
        s+=x
        x=pow(x,2,m)
print(s)