a,b,c,x,y=map(int,input().split())

if a+b<2*c:
    print(a*x+b*y)
else:
    ans=0
    if x>=y:
        ans+=y*2*c
        x-=y
        ans+=x*min(2*c,a)
    else:
        ans+=x*2*c
        y-=x
        ans+=y*min(2*c,b)
    print(ans)

