A, B, C, X, Y = map(int, input().split())
if A + B >= C * 2:
    price = min(X, Y) * C * 2
    tmp = min(X,Y)
    X = X - tmp
    Y = Y - tmp
    if A * X < C * X * 2:
        price += A * X
        X -= X
    if B * Y < C * Y * 2:
        price += B * Y
        Y -= Y
    price += C * 2 * max(X, Y)
    print(price)

else:
    print(A * X + B * Y)