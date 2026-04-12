A, B, C, X, Y = map(int, input().split())
tmp = min(X, Y)
ans = 0
if A + B <= 2 * C:
    ans = (X * A) + (Y * B)
else:
    ans = 2 * C * tmp
    if X > Y:
        if A > 2 * C:
            ans += (X - tmp) * (2 * C)
        else:
            ans += (X - tmp) * A
    elif Y > X:
        if B > 2 * C:
            ans += (Y - tmp) * (2 * C)
        else:
            ans += (Y - tmp) * B
print(ans)