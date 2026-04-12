a, b, c, x, y = map(int, input().split())
if a+b < 2*c:
    print(x*a+y*b)
elif a > 2*c:
    print(x*2*c+max(0, y-x)*min(b, 2*c))
elif b > 2*c:
    print(y*2*c+max(0, x-y)*min(a, 2*c))
elif x >= y:
    print(y*2*c+(x-y)*a)
else:
    print(x*2*c+(y-x)*b)
