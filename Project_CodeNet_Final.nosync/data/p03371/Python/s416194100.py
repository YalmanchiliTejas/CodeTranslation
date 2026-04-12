A, B, C, X, Y = map(int, input().split(' '))
cost = 0
if A + B <= 2 * C:
    cost = A * X + B * Y
else:
    Z = min(X, Y)
    X -= Z
    Y -= Z
    cost = 2 * C * Z
    if X >= 1 and A >= 2 * C:
        cost += 2 * C * X
        X = 0
    elif X >= 1:
        cost += A * X
        X = 0
    if Y >= 1 and B >= 2 * C:
        cost += 2 * C * Y
        Y = 0
    elif Y >= 1:
        cost += B * Y
        Y = 0
print(cost)