a, b, c, x, y = map(int, input().split())
ret = 0
if 2 * c <= a + b:
  m = min(x, y)
  ret += m * 2 * c
  x -= m
  y -= m
ret += min(2 * c, a) * x
ret += min(2 * c, b) * y
print(ret)
