a, b, c, x, y = map(int, input().split())

s = a * x + b * y
t = c * max(x, y) * 2
u = c * min(x, y) * 2 + a * (x - min(x, y)) + b * (y - min(x, y))

print(min(s, t, u))