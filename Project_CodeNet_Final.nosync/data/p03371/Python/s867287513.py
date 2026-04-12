A, B, C, X, Y = [int(_) for _ in input().split()]
M = max(X, Y)
print(min(2 * C * M, 2 * C * (X + Y - M) + A *
          (M - Y) + B * (M - X), A * X + B * Y))
