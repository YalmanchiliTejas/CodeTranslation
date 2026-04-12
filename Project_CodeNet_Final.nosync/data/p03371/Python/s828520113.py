a, b, c, x, y = map(int, input().split())
if min(a + b, 2 * c) == 2 * c:
    if x >= y:
        print(min(2 * c * y + (x - y) * a, 2 * c * x))
    
    else:
        print(min(2 * c * x + (y - x) * b, 2 * c * y))

else:
    print(x * a + y * b)