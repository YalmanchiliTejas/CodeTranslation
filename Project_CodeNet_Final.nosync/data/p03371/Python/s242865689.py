a, b, c, x, y = map(int, input().split())
if a+b<2*c:
    print(a*x+b*y)
else:
    if x > y:
        amari = x - y
        if a > 2*c:
            print(2*c*y + amari*2*c)
        else:
            print(2*c*y + amari*a)
    else:
        amari = y - x
        if b > 2*c:
            print(2*c*x + amari*2*c)
        else:
            print(2*c*x + amari*b)