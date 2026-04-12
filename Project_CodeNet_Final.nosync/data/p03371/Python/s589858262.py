A, B, C, X, Y = map(int, input().split())

if A + B > 2 * C:
    z = min(X, Y)
    x, y = X - z, Y - z
    ans = 2 * C * z + min(A, 2 * C) * x + min(B, 2 * C) * y
else:
    ans = A * X + B * Y

print(ans)