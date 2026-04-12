A, B, C, X, Y = map(int, input().split())
ans = 0

if 2 * C <= A + B:
    tmp = min(X, Y)
    ans += tmp * 2 * C
    X -= tmp
    Y -= tmp
    if X == 0:
        if 2*C <= B:
            ans += Y * 2 * C
        else:
            ans += Y * B
    if Y == 0:
        if 2*C <= A:
            ans += X * 2 * C
        else:
            ans += X * A
else:
    if 2 * C <= B:
        ans += 2 * C * Y
        X -= Y
        if X >= 1:
            ans += min(X*A, X*2*C)
    elif 2 * C <= A:
        ans += 2 * C * X
        Y -= X
        if Y >= 1:
            ans += min(Y*B, Y*2*C)
    else:
        ans += A*X + B*Y
print(ans)
