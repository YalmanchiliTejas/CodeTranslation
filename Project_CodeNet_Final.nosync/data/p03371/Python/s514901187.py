A, B, C, X, Y = map(int, input().split())

if A+B < 2*C:
    print(A*X + B*Y)
else:
    ans = 0
    num = 0
    if X < Y:
        ans += 2 * C * X
        num = Y - X
        if B > 2*C:
            ans += 2 * C * num
        else:
            ans += B * num
    else:
        ans += 2 * C * Y
        num = X - Y
        if A > 2*C:
            ans += 2 * C * num
        else:
            ans += A * num
    print(ans)