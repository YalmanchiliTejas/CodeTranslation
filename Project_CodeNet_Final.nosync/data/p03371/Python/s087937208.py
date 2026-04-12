A, B, C, X, Y = map(int, input().split())
ans = 0
if A + B >= 2 * C:
    AB = min(X, Y)
    ans += 2 * AB * C
    X -= AB
    Y -= AB
if A >= 2 * C:
    AB = X
    ans += 2 * X * C
    X -= AB
    Y -= AB
if B >= 2 * C:
    AB = Y
    ans += 2 * Y * C
    X -= AB
    Y -= AB

ans += A * max(0, X)
ans += B * max(0, Y)

print(ans)