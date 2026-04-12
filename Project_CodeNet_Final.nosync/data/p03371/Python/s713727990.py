A, B, C, X, Y = map(int, input().split())
ans = 0
if A + B <= 2 * C:
    ans = A * X + B * Y
else:
    a = min(X, Y)
    ans += a * 2 * C
    X -= a
    Y -= a
    ans += X * min(A, 2*C)
    ans += Y * min(B, 2*C)

print(ans)
