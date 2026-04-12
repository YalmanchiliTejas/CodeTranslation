a,b,c,x,y = map(int,input().split())
if 2*c <= a+b:
    if x<=y:
        if 2*c <= b:
            print(2*c*y)
        else:
            print(2*c*x+b*(y-x))
    else:
        if 2*c <= a:
            print(2*c*x)
        else:
            print(2*c*y+a*(x-y))
else:
    print(a*x+b*y)