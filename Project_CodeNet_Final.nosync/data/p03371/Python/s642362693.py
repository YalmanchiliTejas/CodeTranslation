a, b, c, x, y = [int(i) for i in input().split()]
print((2 * c * min(x, y) + min(a * (x - y), 2 * c * (x - y)) if x > y else 2 * c * min(x, y) + min(b * (y - x), 2 * c * (y - x))) if a + b > c * 2 else a * x + b * y)
