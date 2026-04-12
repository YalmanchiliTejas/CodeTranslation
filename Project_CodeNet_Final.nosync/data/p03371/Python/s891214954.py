A, B, C, X, Y = list(map(int, input().split()))

if A+B > C * 2:
    if X > Y:
        X, Y = Y, X
        A, B = B, A
    if C * 2 < B:
        print(Y*C*2)
    else:
        print(X*C*2 + (Y-X)*B)
else:
    print(X*A + Y*B)