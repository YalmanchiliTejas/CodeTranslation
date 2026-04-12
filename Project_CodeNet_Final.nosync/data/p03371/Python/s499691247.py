A,B,C,X,Y = map(int,input().split())

fee = 0

if A+B<= 2*C:
    fee += (A+B)*min(X,Y)
    if X > Y:
        if A > 2*C:
            fee += 2*C*(X-Y)
        else:
            fee += A*(X-Y)
    elif Y > X:
        if B > 2*C:
            fee += 2*C*(Y-X)
        else:
            fee += B*(Y-X)
else:
    fee =2*C*min(X,Y)
    if X > Y:
        if A > 2*C:
            fee += 2*C*(X-Y)
        else:
            fee += A*(X-Y)
    elif Y > X:
        if B > 2*C:
            fee += 2*C*(Y-X)
        else:
            fee += B*(Y-X)

print(fee)