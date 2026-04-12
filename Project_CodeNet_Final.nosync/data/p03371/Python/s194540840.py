a,b,c,x,y=map(int,input().split())
if a+b<=c*2:
    print(a*x+b*y)
else:
    if x<y:
        ans=c*2*x
        y-=x
        ans+=min(c*2*y,b*y)
        print(ans)
    else:
        ans=c*2*y
        x-=y
        ans+=min(c*2*x,a*x)
        print(ans)