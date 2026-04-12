a, b, c, x, y = map(int, input().split())
min_price = 10 ** 9
for i in range(10 ** 5 + 1):
  price = i * 2 * c + max(0, x - i) * a + max(0, y - i) * b
  if price < min_price:
    min_price = price
print(min_price)