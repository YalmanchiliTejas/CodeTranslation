a, b, c, x, y = map(int, input().split())
if a + b < 2*c:
    print(a*x + b*y)
elif x<=y and b <= 2 *c:
    print(c*2*x + (y-x)*b)
elif x>=y and a <= 2*c:
    print(c*2*y + (x-y)*a)
elif x <= y and b > 2*c:
    print(c*2*y)
elif x >= y and a > 2*c:
    print(c*2*x)
