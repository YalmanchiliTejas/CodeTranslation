# -*- coding: utf-8 -*-
a, b, c, x, y = map(int, input().split())

total = a * x + b * y
if a + b > 2 * c:
  total = 2 * c * min(x, y)
  if x > y:
    total += (x - y) * min(a, 2 * c)
  elif y > x:
    total += (y - x) * min(b, 2 * c)
print(total)
