a, b, c, x, y = map(int, input().split())
sum = 0
if 2 * c < a + b:
  sum += min(x, y) * 2 * c
  if min(x, y) == x:
    if 2 * c < b:
      sum += (y - x) * 2 * c
    else:
      sum += (y - x) * b
  else:
    if 2 * c < a:
      sum += (x - y) * 2 * c
    else:
      sum += (x - y) * a
else:
  sum += x * a + y * b

print(sum)