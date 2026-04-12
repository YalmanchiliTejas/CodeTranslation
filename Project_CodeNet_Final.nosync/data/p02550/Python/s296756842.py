n,x,m=map(int,input().split())
l=[x]
n-=1
f=-1
while(n>0):
    x=x*x
    x%=m
    if x in l:
        for i in range(len(l)):
            if x==l[i]:
                f=i
                s=l[i:].copy()
                break
    if f!=-1:
        break
    l.append(x)
    n-=1

if n==0:
    print(sum(l))
else:
    ans=sum(l)
    l=s.copy()
    ans+=sum(l)*(n//len(l))
    c=n%len(l)
    f=0
    while(c!=0):
        ans+=l[f]
        c-=1
        f+=1
    print(ans)





