A, B, C, X, Y = map(int, input().split())
if A + B <= C * 2:
    print(A * X + B * Y)
else:
    if X >= Y:
        if A >= 2 * C:
            print(C * Y * 2 + 2 * C * (X - Y))
        else:
            print(C * Y * 2 + A * (X - Y))
    else:
        if B >= 2 * C:
            print(C * X * 2 + 2 * C * (Y - X))
        else:
            print(C * X * 2 + B * (Y - X))
