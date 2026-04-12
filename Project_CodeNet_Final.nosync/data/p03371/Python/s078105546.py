A, B, C, X, Y = map(int, input().split())

if A+B > 2*C:
    m = C*min(X, Y)*2
    if X >= Y:
        rem = X-Y
        tmp = min(A*rem, C*2*rem)
    else:
        rem = Y-X
        tmp = min(B*rem, C*2*rem)
    print(m+tmp)
else:
    AX = A * X
    BY = B * Y
    print(AX+BY)