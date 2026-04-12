A, B, C, X, Y = map(int, input().split())
cost = 0
if A + B <= 2 * C:
    cost = A * X + B * Y
elif A + B > 2 * C:
    if X > Y:
        cost = C * 2 * Y
        if 2 * C < A:
            cost += 2 * C * (X - Y)
        else:
            cost += A * (X - Y)
    elif Y >= X:
        cost = C * 2 * X
        if 2 * C < B:
            cost += 2 * C * (Y - X)
        else:
            cost += B * (Y - X)
print(cost)