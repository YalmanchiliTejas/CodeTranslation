A, B, C, X, Y = map(int, input().split())
ans = 0

if A + B <= 2 * C:
    ans = A * X + B * Y
elif A + B >= 2 * C:
    ans += min(X, Y) * (2 * C)
    if X > Y:
        ans += min((X - Y) * A, (X - Y) * 2 * C)
    else:
        ans += min((Y - X) * B, (Y - X) * 2 * C)
print(ans)