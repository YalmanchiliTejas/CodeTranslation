a, b, c, x, y = map(int, input().split())

if a+b > 2*c:
    if x<=y:
        if b>2*c:
            print(2*x*c+ (y-x)*2*c)
        else:
            print(x*2*c+(y-x)*b)
    else:
        if a> 2*c:
            print(2*y*c+(x-y)*2*c)
        else:
            print(y*2*c+(x-y)*a)
else:
    print(a*x+b*y)
