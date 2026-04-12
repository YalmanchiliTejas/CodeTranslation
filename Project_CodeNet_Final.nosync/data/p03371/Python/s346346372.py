a,b,c,x,y = map(int,input().split())


if a+b <= 2*c:
    print(a*x+b*y)
else:
    if x>=y:
        if a <= 2*c:
            print(y*(2*c)+a*(x-y))
        else:
            print(2*c*x)
    else:
        if b<= 2*c:
            print(x*2*c+b*(y-x))
        else:
            print(2*c*y)