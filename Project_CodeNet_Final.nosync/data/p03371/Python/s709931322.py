A, B, C, X, Y = [int(i) for i in input().split(' ') ]


BB = B if B < 2*C else 2 * C
AA = A if A < 2 * C else 2 * C



if X < Y:
    R1 = BB * (Y - X)
elif X > Y:
    R1 = AA * (X -Y)
else:
    R1 = 0

if A + B > 2 * C:
    R2 = min(X,Y) * 2 * C
else:
    R2 = min(X,Y) * (A+B)

print(R1 + R2)