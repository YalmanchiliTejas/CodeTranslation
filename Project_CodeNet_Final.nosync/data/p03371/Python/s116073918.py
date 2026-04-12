a, b, c, x, y = map(int, input().split())
total = 0
if x >= y:
    total = min(a*x+b*y, c*x*2, c*y*2+a*(x-y))
else:
    total = min(a*x+b*y, c*y*2, c*x*2+b*(y-x))
print(total)