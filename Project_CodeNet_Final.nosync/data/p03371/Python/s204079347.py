A, B, C, X, Y = map(int, input().split())

ans = 0

if A + B > 2 * C:
    buy = min(X, Y)
    ans += buy * 2 * C
    X -= buy
    Y -= buy

if X > 0:
    if A > 2 * C:
        ans += X * 2 * C
    else:
        ans += X * A

if Y > 0:
    if B > 2 * C:
        ans += Y * 2 * C
    else:
        ans += Y * B

print(ans)
