a, b, c, x, y = map(int, input().split())

p = (a + b) / 2
 
if x == y:
    res = min(a * x + b * y, c * x * 2)
elif x > y:
    res = min(a * x + b * y, c * x * 2, c * y * 2 + a * (x - y))
else:
    res = min(a * x + b * y, c * y * 2, c * x * 2 + b * (y - x))
 
print(res)