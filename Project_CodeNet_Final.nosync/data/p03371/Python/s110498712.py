a,b,c,x,y = map(int,input().split())
ans = 0
if a+b>=c*2:
    ans = c*2*min(x,y)
    if x>y:
        if a<c*2:
            ans+=(x-y)*a
        else:
            ans+=c*2*(x-y)
    else:
        if b<c*2:
            ans+=(y-x)*b
        else:
            ans+=c*2*(y-x)
    print(ans)
else:
    print(a*x+b*y)