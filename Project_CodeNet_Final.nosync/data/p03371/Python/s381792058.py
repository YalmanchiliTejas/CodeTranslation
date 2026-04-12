A, B, C, X, Y = map(int, input().split())
if A + B > 2 * C:
    a = min(X, Y)
    c = a * 2 * C
    if a == Y:
        if A > 2 * C:
            print(c + 2 * C * (X - a))
        else:
            print(c + (X - a) * A)
    else:
        if B > 2 * C:
            print(c + 2 * C * (Y - a))
        else:
            print(c + (Y - a) * B)
else:
    print(A * X + B * Y)
