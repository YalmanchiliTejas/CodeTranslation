a, b, ab, xa, yb = map(int, input().split())
price = []
for i in range(100001):
    price.append(i * 2 * ab + max(xa - i, 0) * a + max(yb - i, 0) * b)

idx = price.index(min(price))

print(min(price))
