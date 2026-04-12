A, B, C, X, Y = list(map(int, input().split()))
if C * 2 <= (A + B):
    if X>=Y and 2*C>=A:
        print(2*C*Y+A*(X-Y))
    elif Y>=X and 2*C>=B:
        print(2*C*X+B*(Y-X))
    else:
        print(2*C*max(X,Y))
else:
    print(A*X+B*Y)
