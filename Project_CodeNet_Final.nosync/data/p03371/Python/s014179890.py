a, b, c, x, y = map(int, input().split())

ab = min(x, y)
c2 = c * 2
p = 0

if a + b >= c2:
  x -= ab
  y -= ab
  p += c2 * ab

if a >= c2:
  p += c2 * x
  x = 0
  y -= x

if b >= c2:
  p += c2 * y
  y = 0
  x -= y

if x > 0:
  p += a * x

if y > 0:
  p += b * y
  
print(p)