A, B, C, X, Y = map(int, input().split())
Z = min(X, Y)
W = max(X, Y)
print(min(A * X + B * Y, C * Z * 2 + A * max(0, X - Z) + B * max(0, Y - Z), C * W * 2))
