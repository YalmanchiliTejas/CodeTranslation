a,b,c,x,y=map(int,input().split())
if a+b<2*c:
    print(a*x+b*y)
else:
    if x>y:
        if a<2*c:
            print(a*(x-y)+2*c*y)
        else:
            print(2*c*x)
    else:
        if b<2*c:
            print(b*(y-x)+2*c*x)
        else:
            print(2*c*y)