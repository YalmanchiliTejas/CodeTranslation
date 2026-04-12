A, B, C, X, Y = map(int, input().split())
cost = 0
if A + B > 2 * C:
  P = min(X, Y)
  X -= P
  Y -= P
  cost += 2 * C * P
if A > 2 * C:
  cost += 2 * C * X
  X = 0
if B > 2 * C:
  cost += 2 * C * Y
  Y = 0
cost += A * X + B * Y
print(cost)