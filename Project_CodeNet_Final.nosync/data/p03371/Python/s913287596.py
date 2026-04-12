a, b, c, x, y = map(int, input().split())
pay = 0
minxy = min(x, y)
if a + b > c * 2:
  pay += minxy * c * 2
else:
  pay += minxy * a + minxy * b
if x == minxy:
  pay += min((c * 2) * (y - minxy), b * (y - minxy))
else:
  pay += min((c * 2) * (x - minxy), a * (x - minxy))
print(pay)