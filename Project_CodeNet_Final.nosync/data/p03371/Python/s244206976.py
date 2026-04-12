A, B, C, X, Y = list(map(int, input().split()))

ans = 0
if A + B > 2 * C:
    z = min(X, Y)
    X -= z
    Y -= z
    ans += 2 * z * C

# 偏り分
if 2 * C < A:
    k = X
    X -= k
    Y -= k
    ans += 2 * C * k
if 2 * C < B:
    k = Y
    X -= k
    Y -= k
    ans += 2 * C * k

# あまり分
ans += A * max(0, X) + B * max(0, Y)
print(ans)