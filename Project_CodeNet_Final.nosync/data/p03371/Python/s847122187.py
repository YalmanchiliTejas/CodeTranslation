a, b, c, x, y = map(int, input().split())
if a + b < 2 * c:
  print(a * x + b * y)
else:
  if x > y:
    if a < 2 * c:
      print(c * 2 * y + a * (x-y))
    else:
      print(c * 2 * y + c * 2 * (x-y))
  else:
    if b < 2 * c:
      print(c * 2 * x + b * (y-x))
    else:
      print(c * 2 * x + c * 2 * (y-x))
