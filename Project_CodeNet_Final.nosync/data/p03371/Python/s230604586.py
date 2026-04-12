a, b, c, x, y = map(int, input().split())
if x > y:
    print(min(a * x + b * y, a * (x - y) + 2 * c * y, 2 * c * x))
else:
    print(min(a * x + b * y, b * (y - x) + 2 * c * x, 2 * c * y))