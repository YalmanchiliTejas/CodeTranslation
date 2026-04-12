a, b, c, x, y = map(int, input().split())

p1 = a*x + b*y
p2 = c * 2 * max(x, y)
if x >= y:
  p3 = c * 2 * y + a*(x-y)
else:
  p3 = c * 2 * x + b*(y-x) 

print(min(p1,p2,p3))