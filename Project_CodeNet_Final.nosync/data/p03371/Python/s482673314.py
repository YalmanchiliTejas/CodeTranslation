A,B,C,X,Y = map(int,input().split())
if A+B < C*2:
    print(A*X+B*Y)
elif X > Y:
    if A < C*2:
        print(Y*C*2+(X-Y)*A)
    else:
        print(X*C*2)
else:
    if B < C*2:
        print(X*C*2+(Y-X)*B)
    else:
        print(Y*C*2)