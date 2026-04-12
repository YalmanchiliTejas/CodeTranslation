a, b, c, x, y = map(int, input().split())
p = c * 2 * max(x, y)
q= a * x + b * y
r = s = 10 ** 10
if x >= y:
    r = c * 2 * y + a * (x - y)
else:
    s = c * 2 * x + b * (y - x)
print(min(p, q, r, s))