a, b, c, x, y = map(int, input().split())
m = 0
l = 2 * c * max(x, y)
d = abs(x - y)

if c * 2 <= a + b:
    m += 2 * c * min(x, y)
    if x <= y:
        m += b * d
    else:
        m += a * d
    print(min(m, l))
else:
    m += a * x + b * y
    print(m)