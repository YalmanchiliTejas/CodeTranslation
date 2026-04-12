a, b, c, x, y = list(map(int, input().split()))
if a > c*2 and b > c*2:
  if x > y:
    print(x * c * 2)
  else:
    print(y * c * 2)
elif a > c*2:
  if x > y:
    print(x * c * 2)
  else:
    print(x * c * 2 + (y - x) * b)
elif b > c*2:
  if y > x:
    print(y * c * 2)
  else:
    print(y * c * 2 + (x - y) * a)
elif a + b > c*2:
  if x > y:
    print(y * c * 2 + (x - y) * a)
  else:
    print(x * c * 2 + (y - x) * b)
else:
  print(a * x + b * y)