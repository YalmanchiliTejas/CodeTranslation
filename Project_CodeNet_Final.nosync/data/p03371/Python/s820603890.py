a,b,c,x,y=map(int,input().split())
ans=0
if a+b>c*2:
    z=min(x,y)
    ans+=z*c*2
    x-=z
    y-=z

if a>c*2:
    ans+=x*c*2
    x=0
    y=max(0,y-x)
if b>c*2:
    ans+=y*c*2
    y=0
    x=max(0,x-y)
ans+=x*a
ans+=y*b


print(ans)
