A, B, C, X, Y = map(int, input().split())

if A+B<=C*2:
    print(X*A+Y*B)
elif A<=C*2 and B<=C*2:
    if X>=Y:
        print(Y*C*2+(X-Y)*A)
    else:
        print(X*C*2+(Y-X)*B)
elif A>=C*2 and B>=C*2:
    print(max(X, Y)*C*2)
elif A>=C*2:
    if X>=Y:
        print(C*2*X)
    else:
        print(C*2*X+(Y-X)*B)
else:
    if X>=Y:
        print((X-Y)*A+C*2*Y)
    else:
        print(C*2*Y)