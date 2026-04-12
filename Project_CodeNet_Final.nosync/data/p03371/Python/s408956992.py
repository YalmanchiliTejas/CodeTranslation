A, B, C, X, Y = map(int, input().split())
if A + B >= 2 * C:
    print(2 * C * (min(X, Y)) + min(A, 2 * C) * (X - min(X, Y)) + min(B, 2 * C) * (Y - min(X, Y)))
else:
    print(A * X + B * Y)
