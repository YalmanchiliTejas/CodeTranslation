A,B,C,X,Y = map(int,input().split())
if A+B <= C*2:
    print(A*X+B*Y)
else:
    if X >= Y:
        ans = C*2*Y
        d = X-Y
        if A <= C*2:
            ans += A*d
        else:
            ans += C*2*d
    else:
        ans = C*2*X
        d = Y-X
        if B <= C*2:
            ans += B*d
        else:
            ans += C*2*d
    print(ans)