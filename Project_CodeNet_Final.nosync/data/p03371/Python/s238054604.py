a,b,c,x,y=map(int,input().split())
if x>=y:
    if c*2<=min(a,b):
        print(c*2*x)
    elif c*2<=max(a,b):
        if a>=b:
            print(c*2*x)
        else:
            print(c*2*y+a*(x-y))
    elif c*2<=a+b:
        print(c*2*y+a*(x-y))
    else:
        print(a*x+b*y)
else:
    if c*2<=min(a,b):
        print(c*2*y)
    elif c*2<=max(a,b):
        if a<=b:
            print(c*2*y)
        else:
            print(c*2*y+b*(y-x))
    elif c*2<=a+b:
        print(c*2*x+b*(y-x))
    else:
        print(a*x+b*y)