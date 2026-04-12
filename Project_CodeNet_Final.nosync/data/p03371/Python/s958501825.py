A, B, C, X, Y = map(int, input().split())
Z = min(X, Y)
p = 0
if A + B >= C * 2:
  p += C * 2 * Z
else:
  p += (A + B) * Z
X, Y = X-Z, Y-Z
if X > 0:
  if A > 2 * C:
    p += 2 * C * X
  else:
    p += A * X
if Y > 0:
  if B > 2 * C:
    p += 2 * C * Y
  else:
    p += B * Y
print(p)
