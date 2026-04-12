A, B, C, X, Y = map(int, input().split())
if A+B > 2*C:
    if X < Y:
        if B*(Y-X)+2*C*X > 2*C*Y:
            print(2*C*Y)
        else:
            print(B*(Y-X)+2*C*X)
    else:
        if A*(X-Y)+2*C*Y > 2*C*X:
            print(2*C*X)
        else:
            print(A*(X-Y)+2*C*Y)
else:
    print(A*X+B*Y)