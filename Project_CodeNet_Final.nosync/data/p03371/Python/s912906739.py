a, b, c, x, y = map(int, input().split())
total = 0
if a + b > c * 2:
    total += min(x, y) * 2 * c
    if x >= y:
        total += (x - y) * min(a, 2 * c)
    else:
        total += (y - x) * min(b, 2 * c)

else:
    total = x * a + y * b
print(total)
