A,B,C,X,Y = map(int,raw_input().split())
miny=0
if A+B < 2*C:
    miny=A*X+B*Y
else:
    if X<Y:
        if 2*C>B:
            miny=2*C*X + B*(Y-X)
        else:
            miny=2*C*Y
    else:
        if 2*C>A:
            miny=2*C*Y + A*(X-Y)
        else:
            miny=2*C*X

print miny