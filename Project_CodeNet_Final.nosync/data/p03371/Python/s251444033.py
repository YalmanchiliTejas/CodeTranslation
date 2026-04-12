A, B, C, X, Y = map(int, input().split())

ans = 0
# A,B単体で買ったほうがよい場合
if 2 * C >= A + B:
    ans += A * X + B * Y

# Cを買ったほうが良い場合
else:
    if X > Y:
        ans = min((X - Y) * A + 2 * C * Y, 2 * C * X)
    else:
        ans = min((Y - X) * B + 2 * C * X, 2 * C * Y)

print(ans)