A, B, C, X, Y = map(int, input().split())

if C*2 < A+B:
    if X < Y:
        print(min(C*2*X + (Y-X)*B, C*2*Y))
    else:
        print(min(C*2*Y + (X-Y)*A, C*2*X))
else:
    print(A*X+B*Y)


