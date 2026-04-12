ans=0
a,b,c,x,y=map(int,input().split())
if a+b<=2*c:
    ans+=(a+b)*min(x,y)
    if x>=y:
        ans+=a*(x-y)
    else:
        ans+=b*(y-x)
else:
    ans+=2*c*min(x,y)
    if x>=y:
        if a>=c*2:
            ans+=c*2*(x-y)
        else:
            ans+=a*(x-y)
    else:
        if b>=c*2:
            ans+=c*2*(y-x)
        else:
            ans+=b*(y-x)
print(ans)
