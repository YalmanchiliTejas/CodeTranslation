a, b, c, x, y = map(int, input().split())
if x < y: print(min(c * 2 * x + b * (y - x), c * 2 * y, a * x + b * y))
else: print(min(c * 2 * y + a * (x - y), c * 2 * x, a * x + b * y))
