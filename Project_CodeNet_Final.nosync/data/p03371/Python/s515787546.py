A, B, C, X, Y = list(map(int, input().split()))

price1 = X * A + Y * B
price2 = X * 2 * C + (Y - X) * B if Y > X else X * 2 * C
price3 = Y * 2 * C + (X - Y) * A if X > Y else Y * 2 * C
min_price = min(price1, price2, price3)

print(min_price)

