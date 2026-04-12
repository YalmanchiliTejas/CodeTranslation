A, B, C, X, Y = map(int, input().split())
only_c = C * max(X, Y) * 2
not_c = A * X + B * Y
balance = C * X * 2 + B * (Y - X) if X < Y else C * Y * 2 + A * (X - Y)
print(min(only_c, not_c, balance))