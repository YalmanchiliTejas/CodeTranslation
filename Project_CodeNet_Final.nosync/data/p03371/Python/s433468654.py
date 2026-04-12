import math

A, B, C, X, Y = map(int, input().split())

if A + B < C * 2:
    p = A * X + B * Y
else:
    if X > Y:
        p = Y * C * 2
        if A > C * 2:
            p += math.ceil((X - Y) * 2) * C
        else:
            p += (X - Y) * A
    else:
        p = X * C * 2
        if B > C * 2:
            p += math.ceil((Y - X) * 2) * C
        else:
            p += (Y - X) * B

print(p)