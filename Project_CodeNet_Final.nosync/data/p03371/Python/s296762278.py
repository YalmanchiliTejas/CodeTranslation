a, b, c, x, y = map(int, input().split())
if a+b <= 2*c:
    print(a*x + b*y)
else:
    if x > y:
        if a < 2*c:
            print(2*y*c + (x-y)*a)
        else:
            print(2*x*c)
    else:
        if b < 2*c:
            print(2*x*c + (y-x)*b)
        else:
            print(2*y*c)