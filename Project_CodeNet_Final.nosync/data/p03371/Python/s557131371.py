A,B,C,X,Y=map(int,input().split())
if X<Y:
    P=X
    R=Y-X
    if B<2*C:
        Q=B
    else:
        Q=2*C
else:
    P=Y
    R=X-Y
    if A<2*C:
        Q=A
    else:
        Q=2*C
if (A+B)<2*C:
    O=A+B
else:
    O=2*C
print(O*P+Q*R)
