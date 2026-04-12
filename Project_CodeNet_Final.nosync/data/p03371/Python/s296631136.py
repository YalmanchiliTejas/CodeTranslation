A, B, C, X, Y = map(int, input().split())
if A+B <= 2*C:
    print(A*X + B*Y)
else:
    if X >= Y:
        if A >= 2*C:
            print(X*2*C)
        else:
            print(Y*2*C + (X-Y)*A)
    else:
        if B >= 2*C:
            print(Y*2*C)
        else:
            print(X*2*C + (Y-X)*B)