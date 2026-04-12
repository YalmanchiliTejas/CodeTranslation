a,b,c,x,y=list(map(int,input().split()))


mm=min(x,y)

if a+b<c*2:
    ans=a*x+b*y
else:
    ans=c*2*mm
    if x>y:
        if a>c*2:
            ans+=c*2*(x-y)
        else:
            ans+=a*(x-y)
    else:
        if b>c*2:
            ans+=c*2*(y-x)
        else:
            ans+=b*(y-x)
print(ans)