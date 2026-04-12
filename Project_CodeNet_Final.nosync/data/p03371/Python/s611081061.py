A, B, C, X, Y = map(int, input().split())

v1 = A * X + B * Y
v2 = A * max(X-Y, 0) + B * max(Y-X, 0) + C * 2 * min(X, Y)
v3 = C * 2 * max(X, Y)

print(min(v1, v2, v3))
