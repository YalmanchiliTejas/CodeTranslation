A,B,C,X,Y = map(int,input().split())
if A + B <= 2 * C:
    print(X*A+Y*B)
else:
    if X >= Y:
        if A >= 2*C:
            print(2*X*C)
        else:
            print((X-Y)*A + 2*Y*C)
    else:
        if B >= 2*C:
            print(2*Y*C)
        else:
            print((Y-X)*B + 2*X*C)