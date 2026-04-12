a,b,c,x,y=map(int,input().split())
ans=0
if c*2<a+b:
    k=min(x,y)
    x-=k
    y-=k
    ans+=c*2*k
if c*2<a:
    k=x
    x-=k
    y-=k
    ans+=c*2*k
if c*2<b:
    k=y
    x-=k
    y-=k
    ans+=c*2*k
ans+=a*max(0,x)+b*max(0,y)
print(ans)
