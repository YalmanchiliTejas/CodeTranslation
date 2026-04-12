A,B,C,X,Y = list(map(int,input().split()))

Zmax = max(X,Y)
Zmin = min(X,Y)
tot = 0

if A+B >= 2*C:
    if X >= Y:
        if A <= 2*C:
            tot = 2*Zmin *C + (Zmax-Zmin) * A
        else:
            tot = 2*Zmin *C + 2*(Zmax-Zmin) * C
    else:
        if B <= 2*C:
            tot = 2*Zmin *C + (Zmax-Zmin) * B
        else:
            tot = 2*Zmin *C + 2*(Zmax-Zmin) * C
else:
    tot = X*A + Y*B

print(tot)
