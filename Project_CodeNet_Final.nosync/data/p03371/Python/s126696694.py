def f():
    if (A+B) <= C*2:
        return A*X+B*Y
    elif X==Y:
        return X*C*2
    else:
        if X > Y:
            if A > C*2:
                return (C*2)*(X-Y)+Y*C*2
            return A*(X-Y)+Y*C*2
        else:#Yの方が多い
            if B > C*2:
                return (C*2)*(Y-X)+X*C*2
            return B*(Y-X)+X*C*2
A,B,C,X,Y = map(int,input().split())
print(f())