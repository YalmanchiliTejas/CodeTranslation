A, B, C, X, Y = map(int, input().split())

price = 0

if A + B > 2 * C:
	price += min(X,Y) * 2 * C
	price += (X - min(X,Y)) * min(A, 2*C)
	price += (Y - min(X,Y)) * min(B, 2*C)
else:
	price = A * X + B * Y

print(price)