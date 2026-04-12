A, B, C, X, Y = map(int, input().split())

ans = float("inf")

# 全部ミックスピザ
ans = min(2 * C * max(X, Y), ans)
# 普通に買う
ans = min(A * X + B * Y, ans)
# 多少はミックスも買う
if X >= Y:
    tmp = 2 * C * Y
    tmp += min((X - Y) * A, 2 * (X - Y) * C)
    ans = min(tmp, ans)
else:  # X < Y
    tmp = 2 * C * X
    tmp += min((Y - X) * B, 2 * (Y - X) * C)
    ans = min(tmp, ans)

print(ans)
