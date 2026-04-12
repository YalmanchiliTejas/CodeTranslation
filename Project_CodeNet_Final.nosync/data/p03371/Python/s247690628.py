A, B, C, X, Y = map(int, input().split())

print(min(
          A * X + B * Y,
          C * 2 * min(X, Y) + A * max(0, (X - min(X, Y))) + B * max(0, (Y - min(X, Y))),
          C * 2 * max(X, Y) + A * max(0, (X - max(X, Y))) + B * max(0, (Y - max(X, Y)))))
