a, b, c, x, y = map(int, input().split())
if a+b <= 2*c:
    print(a*x+b*y)
else:
    if x < y:
        print(min(c*x*2+b*(y-x), 2*y*c))
    else:
        print(min(a*(x-y)+c*y*2, 2*x*c))