A, B, C, X, Y = map(int, input().split())
a = A * X + B * Y
b = C * max(X, Y) * 2
c = A * (X - Y) + 2 * C * Y
d = B * (Y - X) + 2 * C * X
e = max(c, d)
ans = min(a, b, e)
print(ans)