a, b, c, x, y = map(int, input().split())
cost = 0
if a + b > 2 * c:
    ma = max(x,y)
    nc = min(x, y)
    x -= nc
    y -= nc
    cost = min(ma * 2 * c, nc * 2 * c + x * a + y * b)
else:
    cost = a * x + b * y
print(cost)
