A, B, C, X, Y = map(int, input().split())
ans = min(A * X + B * Y, 2 * C * X + B * abs(X - Y), 2 * C * Y + A * abs(X - Y), 2 * C * max(X, Y))
print(ans)
