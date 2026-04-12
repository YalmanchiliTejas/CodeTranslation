a,b,c,x,y=map(int,input().split())
if a+b<=2*c: print(a*x+b*y)
else:
    ans=min(x,y)*2*c
    dif=abs(x-y)
    if x>y:
        if a>=2*c:
            ans+=2*dif*c
        else:
            ans+=a*dif
    else:
        if b>=2*c:
            ans+=2*dif*c
        else:
            ans+=b*dif
    print(ans)