a, b, c, x, y = map(int, input().split())
if (a + b) > c * 2:
  if x > y:
    if a > c * 2:
      print(c * 2 * x)
    if a <= c * 2:
      print(a * (x - y) + c * 2 * y)
  if x < y:
    if b > c * 2:
      print(c * 2 * y)
    if b <= c * 2:
      print(b * (y - x) + c * 2 * x)
  if x == y:
    print(c * 2 * x)
elif (a + b) <= c * 2:
  print(a * x + b * y)
