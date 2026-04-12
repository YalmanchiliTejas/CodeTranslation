a, b, c, x, y = map(int, input().split())
if(a + b < 2 * c):
    print(a * x + b * y)
else:
    if(x > y):
        print(min(x * 2 * c, y * 2 * c + (x - y) * a))
    else:
        print(min(y * 2 * c, x * 2 * c + (y - x) * b))