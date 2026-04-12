A, B, C, X, Y = map(int, input().split())
a = 0
b = 0
c = 0
if A + B > 2 * C:
  c += 2 * min(X, Y)
  if X > Y:
    if A > 2 * C:
      c += 2 * (X - Y)
    else:
      a += X - Y
  else:
    if B > 2 * C:
      c += 2 * (Y - X)
    else:
      b += Y - X
else:
  a += X
  b += Y
print(A * a + B * b + C * c)