A,B,C,X,Y = map(int,input().split())

if A+B < 2*C:
    print(A*X + B*Y)
else:
    if X > Y:
        if A > 2*C:
            print(2*C*X)
        else:
            print(2*C*Y + A*(X-Y))
    elif X < Y:
        if B > 2*C:
            print(2*C*Y)
        else:
            print(2*C*X + B*(Y-X))
    else:
        print(2*C*X)