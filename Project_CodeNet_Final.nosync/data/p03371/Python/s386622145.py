a, b, c, x, y = map(int, input().split())
mi, ma = min(x, y), max(x, y)
print(int(min(mi * c * 2 + a * (x-mi) + b * (y-mi),
              ma * c * 2,
              x * a + y * b)))