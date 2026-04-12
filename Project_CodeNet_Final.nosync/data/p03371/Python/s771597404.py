A, B, C, X, Y = map(int, input().split())

cost = 0
if (A+B) < 2*C:
  cost += (A * X + B * Y)
elif (A+B) >= 2*C:
  cost += (C * min(X, Y) * 2)
  if max(X, Y) == X:
    if A < 2*C:
      cost += (A * abs(X-Y))
    else:
      cost += (2 * C * abs(X-Y))
  else:
    if B < 2*C:
      cost += (B * abs(X-Y))
    else:
      cost += (2 * C * abs(X-Y))
print(cost)
  