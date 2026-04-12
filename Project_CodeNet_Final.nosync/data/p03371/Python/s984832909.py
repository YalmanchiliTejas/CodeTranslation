# input
A, B, C, X, Y = map(int, input().split())

ans = 0

if A + B >= 2 * C:
    if Y >= X:
        if B >= 2 * C:
            ans = 2 * C * Y
        else:
            ans = 2 * C * X + B * (Y - X)
    else:
        if A >= 2 * C:
            ans = 2 * C * X
        else:
            ans = 2 * C * Y + A * (X - Y)
else:
    ans = A * X + B * Y

print(ans)