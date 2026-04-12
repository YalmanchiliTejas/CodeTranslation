a, b, c, x, y = map(int, input().split())
z = min(x, y)
if a + b >= c * 2:
    print(min(c * z * 2 + a * (x - z) + b * (y - z), c * max(x, y) * 2))
else:
    print(a * x + b * y)