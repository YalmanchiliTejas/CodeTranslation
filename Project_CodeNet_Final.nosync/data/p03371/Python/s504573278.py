a, b, c, x, y = [int(i) for i in input().split()]

z = min(x, y)
money = 0
if a + b > c * 2:
  money += z * c * 2
  if x > y:
    if a > c * 2:
      money += (x - z) * c * 2
    else:
      money += (x - z) * a
  else:
    if b > c * 2:
      money += (y - z) * c * 2
    else:
      money += (y - z) * b
else:
  money += x * a + y * b
print(money)