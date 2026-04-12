a, b, c, x, y = map(int, input().split())
if x < y:
  a, b, x, y = b, a, y, x # x >= y
m1 = y * 2 * c + (x - y) * a
m2 = a * x + b * y
m3 = x * c * 2
print(min(m1, m2, m3))