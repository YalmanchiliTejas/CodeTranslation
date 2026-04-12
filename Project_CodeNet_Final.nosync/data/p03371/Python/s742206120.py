a, b, c, x, y = map(int, input().split())
if a + b <= 2 * c:
  print(a * x + b * y)
elif max(a, b) <= 2 * c:
  m = min(x, y)
  print(2 * c * m + a * (x - m) + b * (y - m))
elif a <= 2 * c:
  print(2 * c * y + a * max(0, x - y))
elif b <= 2 * c:
  print(2 * c * x + b * max(0, y - x))
else:
  print(2 * c * max(x, y))
