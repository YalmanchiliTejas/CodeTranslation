a, b, c, x, y = map(int, input().split())

c = c * 2

total = 0

minimum = min(x,y)

if a + b > c:
  total += minimum * c
  x -= minimum
  y -= minimum

if x > 0:
  if a > c:
    total += x * c
  else:
    total += x * a

if y > 0:
  if b > c:
    total += y * c
  else:
    total += y * b

print(total)
