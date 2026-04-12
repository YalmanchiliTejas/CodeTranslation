A, B, C, X, Y = map(int, input().split())

if A + B <= 2 * C:
    print(A * X + B * Y)
    exit()

else:
    if X > Y:
        if A > 2 * C:
            print(C * 2 * X)
            exit()
        else:
            print(C * 2 * Y + A * (X - Y))
            exit()
    elif X < Y:
        if B > 2 * C:
            print(C * 2 * Y)
            exit()
        else:
            print(C * 2 * X + B * (Y - X))
            exit()
    else:
        print(C * 2 * X)
        exit()