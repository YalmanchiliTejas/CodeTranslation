A, B, C, X, Y = map(int, input().split())


if A + B <= 2 * C:
    ans = Y * B + X * A
else:
    if X > Y:
        ans = min(2 * C * Y + (X-Y) * A, 2*C*X)
    else:
        ans = min(2 * C * X + (Y-X) * B, 2*C*Y)

print(ans)
