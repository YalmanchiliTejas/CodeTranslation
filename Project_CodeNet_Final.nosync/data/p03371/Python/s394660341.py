A, B, C, X, Y = map(int, input().split())

plan1 = A * X + B * Y
if X > Y:
    plan2 = 2 * C * X
    plan3 = 2 * C * Y + A * (X - Y)
else:
    plan2 = 2 * C * Y
    plan3 = 2 * C * X + B * (Y - X)

print(min(plan1, plan2, plan3))
