a, b, c, x, y = [int(i) for i in input().split()]

if a + b // 2 < c:
    c = a + b // 2

n = a * x + b * y
m = c * max(x, y) * 2

v = 0

if x > y:
    v = c * y * 2 + a * (x-y)
else:
    v = c * x * 2 + b * (y-x)

print(min(n, v, m))