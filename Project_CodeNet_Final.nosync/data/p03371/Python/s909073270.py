A, B, C, X, Y = (int(i) for i in input().split()) 
 
if A + B > 2 * C :
    if X > Y:
        if A > C * 2:
            print(Y * 2 * C + (X - Y) * C * 2)
        else:
            print(Y * 2 * C + (X - Y) * A)
    else:
        if B > C * 2:
            print(X * 2 * C + (Y - X) * C * 2)
        else:
            print(X * 2 * C + (Y - X) * B)
else:
    print(A * X + B * Y)