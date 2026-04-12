A,B,C,X,Y=map(int, input().split())
if A+B<=C:
    print(X*A+Y*B)
else:
    ab=min(X,Y)*C*2
    if X>=Y:
        mod=min((X-Y)*A,(X-Y)*2*C)
    else:
        mod=min((Y-X)*B,(Y-X)*2*C)
    print(min(ab+mod,A*X+B*Y))