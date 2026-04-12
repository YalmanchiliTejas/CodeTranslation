A,B,C,X,Y = map(int,input().split())
if A+B > 2*C:
    AB = min(X,Y)
    if X<Y:
        if B <= 2*C:
            print(2*C*AB + A*(X-AB) + B*(Y-AB))
        else:
            print(2*C*Y)
    else:
        if A <= 2*C:
            print(2*C*AB + A*(X-AB) + B*(Y-AB))
        else:
            print(2*C*X)
else:
    print(A*X+B*Y)