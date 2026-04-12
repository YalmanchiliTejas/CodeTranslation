a,b,c,x,y=map(int,input().split())

a,b,x,y=(a,b,x,y) if x<=y else(b,a,y,x)
if 2*c<=a+b:
    print(2*x*c+(y-x)*min(2*c,b))
else:
    a,b,x,y=(a,b,x,y) if a<=b else(b,a,y,x)
    if a>=2*c:
        print(2*c*max(x,y))
    elif b>=2*c:
        print(2*c*y+a*max(0,x-y))
    else:
        print(a*x+b*y)