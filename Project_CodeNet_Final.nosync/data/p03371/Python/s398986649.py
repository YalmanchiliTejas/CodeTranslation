a, b, c, x, y = map(int, input().split())
price = a * x + b * y

for i in range(0, max(2*x + 1, 2*y + 1), 2):
    price_new = int(max(a * (x - i/2), 0) + max(b * (y - i/2), 0) + c * i)
    if price > price_new:
        price = price_new
print(price)