a,b,c,x,y=map(int,input().split())
if a+b<2*c:
    print(x*a+y*b)
else:
    ans=2*c*min(x,y)
    if x>y:
        x=x-y
        if a<2*c:
            ans=ans+x*a
        else:
            ans=ans+x*2*c
    else:
        y=y-x
        if b<2*c:
            ans=ans+y*b
        else:
            ans=ans+y*2*c
    print(ans)
