A,B,C,X,Y = map(int,input().split())
if A+B <= 2*C:
    print(A*X+B*Y)
else:
    if X < Y:
        if B <= 2*C:
            print(X*2*C+(Y-X)*B)
        else:
            print(2*Y*C)
    elif X == Y:
        print(2*X*C)
    else:
        if A <= 2*C:
            print(Y*2*C+(X-Y)*A)
        else:
            print(2*X*C)