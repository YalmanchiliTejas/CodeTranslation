a, b, c, x, y = map(int, input().split())
n = (x - y) * a + 2 * c * y if x > y else (y - x) * b + 2 * c * x
print(min(a * x + b * y, 2 * max(x, y) * c, n))