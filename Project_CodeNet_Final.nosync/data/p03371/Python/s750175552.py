A, B, C, X, Y = map(int, input().split())
cost = 0
if A + B > 2 * C:
    Z = min(X, Y)
    cost += 2 * C * Z
    X -= Z
    Y -= Z
    if X > 0 and A > 2 * C:
        cost += 2 * C * X
        X = 0
    elif Y > 0 and B > 2 * C:
        cost += 2 * C * Y
        Y = 0
cost += A * X + B * Y
print(cost)