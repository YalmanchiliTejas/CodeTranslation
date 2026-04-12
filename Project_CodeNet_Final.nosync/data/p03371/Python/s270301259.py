a,b,c,x,y=map(int,input().split())
if a+b<=2*c:
    print(a*x+b*y)
else:
    ans=2*c*min(x,y)
    if x==y:
        print(ans)
    elif x>y:
        d=x-y
        if a<=2*c:
            print(ans+a*d)
        else:
            print(ans+2*c*d)
    else:
        d=y-x
        if b<=2*c:
            print(ans+b*d)
        else:
            print(ans+2*c*d)