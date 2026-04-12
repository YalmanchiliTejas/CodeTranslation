A, B, C, X, Y = map(int, input().split())
if A + B <= 2 * C:
    ans = A * X + B * Y
elif A + B > 2 * C:
    nokori = abs(X - Y)
    if X >= Y and A >= 2 * C:
        ans = C * 2 * X
    if Y >= X and B >= 2 * C:
        ans = C * 2 * Y
    if X >= Y and A <= 2 * C:
        ans = C * 2 * Y + nokori * A
    if Y >= X and B <= 2 * C:
        ans = C * 2 * X + nokori * B
print(ans)