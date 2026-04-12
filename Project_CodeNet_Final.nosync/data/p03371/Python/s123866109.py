A, B, C, X, Y = map(int, input().split())

if A+B > 2*C:
    if X-Y > 0:
        print(min(Y*2*C+(X-Y)*A, X*2*C))
    else:
        print(min(X*2*C+(Y-X)*B, Y*2*C))
else:
    print(A*X+B*Y)
