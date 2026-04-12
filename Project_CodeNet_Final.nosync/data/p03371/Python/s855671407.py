[a, b, ab, x, y] = [int(i) for i in input().split()]
price = []
price.append(a * x + b * y)
if x > y:
    price.append(2 * ab * y + a * (x-y))
else:
    price.append(2 * ab * x + b * (y-x))
price.append(ab * 2 * max(x, y))
print(min(price))