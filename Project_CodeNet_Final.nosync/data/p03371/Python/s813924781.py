A, B, C, X, Y = map(int, input().split())
print(min(
    A * X + B * Y,
    C * X * 2 + B * max(0, Y - X),
    C * Y * 2 + A * max(0, X - Y)
))