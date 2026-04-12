A, B, C, X, Y = map(int, input().split())
if X >= Y:
    p1 = A * X + B * Y
    p2 = 2 * C * Y + A * (X - Y)
    p3 = 2 * C * X
    print(min(p1, p2, p3))
else:
    p1 = p1 = A * X + B * Y
    p2 = 2 * C * X + B * (Y - X)
    p3 = 2 * C * Y
    print(min(p1, p2, p3))