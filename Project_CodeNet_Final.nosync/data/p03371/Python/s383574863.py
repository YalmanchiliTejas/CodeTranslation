A, B, C, X, Y = map(int, input().split())
if A + B > 2 * C:
    base = 2 * C * min(X, Y)
    if X >= Y:
        opt = min(A * (X - Y), 2 * C * (X - Y))
    else:
        opt = min(B * (Y - X), 2 * C * (Y - X))
    ans = base + opt
else:
    ans = A * X + B * Y
print(ans)
