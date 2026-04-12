A, B, AB, X, Y = map(int, input().split())
res = 0
if A + B > 2 * AB:
  res += min(X, Y) * AB * 2
  m = min(X, Y)
  X -= m
  Y -= m
if A > 2 * AB and X > 0:
  res += X * AB * 2
  X -= X
  Y -= X
if B > 2 * AB and Y > 0:
  res += Y * AB * 2
  X -= Y
  Y -= Y
print(res + max(0, X * A) + max(0, Y * B))