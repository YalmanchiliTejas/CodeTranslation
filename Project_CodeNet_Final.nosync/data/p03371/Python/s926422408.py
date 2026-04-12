a, b, c, x, y = map(int, input().split())

p1 = a * x + b * y
# A>C
p = c * 2 * x

if x >= y:
  p = p

else:
  p = p + (y - x) * b
      
# B>C
p2 = c * 2 * y
if x >= y:
  p2 = p2 + (x - y) * a
else:
  p2 =p2
  
print(min(p, p1, p2))