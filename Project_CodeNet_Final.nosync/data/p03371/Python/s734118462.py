A, B, C, X, Y = map(int, input().split())

C *= 2
ans = 0
if A + B <= C:
    ans += A * X + B * Y
else:
    min_num = min(X, Y)
    ans += min_num * C
    X -= min_num
    Y -= min_num
    if X > 0:
        if A > C:
            ans += X * C
        else:
            ans += X * A
    if Y > 0:
        if B > C:
            ans += Y * C
        else:
            ans += Y * B
print(ans)