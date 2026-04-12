a, b, c, x, y = map(int, input().split())
p0 = a * x + b * y
p1 = 2 * c * max(x, y)
a0 = 2 * c * min(x, y) + a * (max(x, y) - min(x, y))
b0 = 2 * c * min(x, y) + b * (max(x, y) - min(x, y))

if x <= y:
    print(min(p0, p1, b0))
else:
    print(min(p0, p1, a0))