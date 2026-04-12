a, b, c, x, y = map(int, input().split())
if a+b > 2*c:
  temp_1 = 2 * min(x, y) * c
  if x > y:
    temp_1 += (x - y) * a
  else:
    temp_1 += (y - x) * b
  temp_2 = 2 * max(x, y) * c
  if temp_1 < temp_2:
    price = temp_1
  else:
    price = temp_2
else:
  price = x * a + y * b
print(price)