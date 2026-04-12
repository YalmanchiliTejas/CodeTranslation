A, B, C, X, Y = list(map(int, input().split()))

m = min(X, Y)
X -= m
Y -= m

price = m * min(A + B, 2 * C)
price += min(A, 2 * C) * X + min(B, 2 * C) * Y
print(price)
