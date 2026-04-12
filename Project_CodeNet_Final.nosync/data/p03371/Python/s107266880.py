A, B, C, X, Y = map(lambda x: int(x), input().split())
price = A * X + B * Y
for Z in range(2, X * 2 + 1 if X > Y else Y * 2 + 1, 2):
    x, y = int(X - Z / 2), int(Y - Z / 2)
    x, y = 0 if x < 0 else x, 0 if y < 0 else y
    next_price = A * x + B * y + C * Z
    if next_price >= price:
        break
    price = next_price
print(price)
