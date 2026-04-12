A, B, C, X, Y = map(int, input().split())
ans = min(A * X + B * Y, 2 * C * max(X, Y), 2 * C * X + B * (Y - X) if X < Y else 2 * C * Y + A * (X - Y))
print(ans)
