A, B, C, X, Y = map(int, input().split())
a1 = A * X + B * Y
a2 = B * (Y - X) + C * 2 * X
a3 = A * (X - Y) + C * 2 * Y
a4 = a3 if X > Y else a2
a5 = C * 2 * max(X, Y)
ans = min(a1, a4, a5)
print(ans)
