a, b, c, x, y = map(int, input().split())

if a + b <= 2 * c:
    price = a * x + b * y
else:
    if x >= y:
        price = min(2 * c * y + a * (x - y), 2 * c * x)
    else:
        price = min(2 * c * x + b * (y - x), 2 * c * y)

print(price)