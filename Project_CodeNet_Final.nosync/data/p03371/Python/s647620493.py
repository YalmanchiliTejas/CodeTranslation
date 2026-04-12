A, B, C, X, Y = map(int, input().split())

if X > Y:
    price = 2 * C * Y + A * (X - Y)
else:
    price = 2 * C * X + B * (Y - X)

print(min(A * X + B * Y, 2 * C * max(X, Y), price))
