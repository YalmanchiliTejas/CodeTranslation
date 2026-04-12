A, B, C, X, Y = map(int,input().split())
ans = 0
if 2*C < A:
    ans += 2*X*C
    if X >= Y:
        print(ans)
    else:
        Y -= X
        if 2*C < B:
            ans += 2*Y*C
            print(ans)
        else:
            ans += Y * B
            print(ans)
elif 2*C < B:
    ans += 2*Y*C
    if X <= Y:
        print(ans)
    else:
        X -= Y
        ans += X * A
        print(ans)
else:
    if A + B < 2*C:
        print(A*X+B*Y)
    else:
        if X < Y:
            ans += X*2*C
            ans += (Y-X)*B
            print(ans)
        else:
            ans += Y*2*C
            ans += (X-Y)*A
            print(ans)
