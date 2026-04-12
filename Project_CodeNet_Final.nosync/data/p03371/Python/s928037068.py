A, B, C, X, Y = map(int, input().split())
if A+B <= C*2:
    print(A*X+B*Y)
if A+B > C*2:
    if X>Y:
        if A*(X-Y) > C*(X-Y)*2:
            print(C*2*X)
        else:
            print(C*2*Y + A*(X-Y))
    else:
        if B*(Y-X) > C*(Y-X)*2:
            print(C*2*Y)
        else:
            print(C*2*X + B*(Y-X))