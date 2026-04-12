A, B, C, X, Y = map(int, input().split())

price1 = A * X + B * Y
price2 = min(X, Y) * 2 * C + abs(X - Y) * (A if X > Y else B)
price3 = max(X, Y) * 2 * C

print(min(price1, price2, price3))
