a, b, c, x, y = [int(i) for i in input().split(" ")]

s = 0

if a + b > 2 * c:
    m = min(x, y)
    s += 2 * c * m
    x -= m
    y -= m
    if a > 2 * c:
        s += 2 * c * x
    else:
        s += a * x
    if b > 2 * c:
        s += 2 * c * y
    else:
        s += b* y
else:
    s += a * x + b * y

print(s)