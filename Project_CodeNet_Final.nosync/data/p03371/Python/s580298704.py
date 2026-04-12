a, b, c, x, y = map(int, input().split())
if a + b <= 2 * c:
    print(a * x + b * y)
else:
    if x >= y:
        if a <= 2 * c:
            print((x - y) * a + y * 2 * c)
        else:
            print(2 * x * c)
    else:
        if b <= 2 * c:
            print((y - x) * b + x * 2 * c)
        else:
            print(2 * y * c)