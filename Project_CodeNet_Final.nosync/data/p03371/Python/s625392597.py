a,b,c,x,y = map(int, input().split())
if x == y:
    if a+b >= 2*c:
        print(2*c*x)
    else:
        print((a+b)*x)
elif x > y:
    if a+b >= 2*c:
        if a >= 2*c:
            print(2*c*x)
        else:
            print(2*c*y + a*(x-y))
    else:
        if a >= 2*c:
            print((a+b)*y + 2*c*(x-y))
        else:
            print((a+b)*y + a*(x-y))
else:
    if a+b >= 2*c:
        if b >= 2*c:
            print(2*c*y)
        else:
            print(2*c*x + b*(y-x))
    else:
        if b >= 2*c:
            print((a+b)*x + 2*c*(y-x))
        else:
            print((a+b)*x + b*(y-x))