a,b,c,x,y = map(int,input().split())

if 2*c >= a+b:
    print(a*x +b*y)
else:
    if x < y:
        if b < 2*c:
            print(2*c*x +b*(y-x))
        else:
            print(2*c*y)
    else:
        if a < 2*c:
            print(2*c*y +a*(x-y))
        else:
            print(2*c*x)

