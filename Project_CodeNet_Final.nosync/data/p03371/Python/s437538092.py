A, B, C, X, Y = map(int, input().split())

x1 = A * X + B * Y
if X > Y:
  x2 = Y * 2 * C + (X - Y) * A
else:
  x2 = X * 2 * C + (Y - X) * B
x3 = max(X, Y) * 2 * C

print(min(x1, x2, x3))