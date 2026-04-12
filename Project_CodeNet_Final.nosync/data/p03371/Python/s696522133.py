A, B, C, X, Y = map(int, input().split())
cost = 0
if (A + B) > 2 * C:
    cost += C * min(X, Y) * 2
    if X > Y:
        if A > 2 * C:
            cost += C * (X - Y) * 2
        else:
            cost += A * (X - Y)
    else:
        if B > 2 * C:
            cost += C * (Y - X) * 2
        else:
            cost += B * (Y - X)
else:
    cost += A * X + B * Y
print(cost)