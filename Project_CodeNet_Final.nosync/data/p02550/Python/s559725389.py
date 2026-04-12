n,x,m=map(int,input().split())
s=x
t={x}
u=[x]
for i in range(1,n):
    if(x:=pow(x,2,m))in t:
        j=u.index(x)
        s=sum(u[:j])
        u=u[j:]
        s+=(n-j)//len(u)*sum(u)
        s+=sum(u[:(n-j)%len(u)])
        break
    s+=x
    t|={x}
    u+=x,
print(s)