a, b, c, x, y = map(int, input().split())
if a + b <= c*2:
    print(x*a + y*b)
elif x >= y:
    print(min(x*2*c, y*2*c + (x-y)*a))
else:
    print(min(y*2*c, x*2*c + (y-x)*b))
