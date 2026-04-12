A, B, C, X, Y = map(int, input().split())

ans1 = A * X + B * Y

if X > Y:
    ans2 = 2 * C * Y + A * (X - Y)
else:
    ans2 = 2 * C * X + B * (Y - X)

ans3 = 2 * C * max(X, Y)

print(min(ans1, ans2, ans3))
    