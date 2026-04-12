a, b, c, x, y = map(int, input().split())

price = 0
if c >= (a + b) / 2:
    price += a * x + b * y

elif x <= y:
    price += c * 2 * x
    if b >= c * 2:
        price += c * 2 * (y - x)
    else:
        price += b * (y - x)

else:
    price += c * 2 * y
    if a >= c * 2:
        price += c * 2 * (x - y)
    else:
        price += a * (x - y)

print(price)

