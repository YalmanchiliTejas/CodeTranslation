A, B, C, X, Y = map(int, input().split())
if A + B <= 2 * C:
    print(A * X + B * Y)
else:
    if X > Y:
        mi = Y
        print(mi * 2 * C + (X - mi) * min(A, 2*C))
    else:
        mi = X
        print(mi * 2 * C + (Y - mi) * min(B, 2*C))