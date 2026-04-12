a, b, c, x, y = map(int, input().split())
if c > (a + b) / 2:
    print(a * x + b * y)
else:
    price = c * min(x, y) * 2
    if x > y:
        price += (x - y) * min(a, 2 * c)
    else:
        price += (y - x) * min(b, 2 * c)
    print(price)
