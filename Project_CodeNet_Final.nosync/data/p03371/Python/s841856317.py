a, b, c, x, y = map(int, input().split())
if a+b <= 2*c:
    print(a*x + b*y)
else:
    if x < y:
        if b >= 2*c:
            print(2*y*c)
        else:
            print(b*(y-x)+2*x*c)
    else:
        if a >= 2*c:
            print(2*x*c)
        else:
            print(a*(x-y)+2*y*c)
