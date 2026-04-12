a, b, c, x, y = map(int, input().split())
v1 = a * x + b * y
min_xy = min(x, y)
v2 = min_xy * 2 * c + (x - min_xy) * a + (y - min_xy) * b
max_xy = max(x, y)
v3 = max_xy * 2 * c
print(min(v1, v2, v3))