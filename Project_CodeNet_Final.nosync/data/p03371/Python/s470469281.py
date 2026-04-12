A, B, C, X, Y = map(int, input().split())

p1 = A * X + B * Y
p2 = max(X, Y) * 2 * C
p3 = min(X, Y) * 2 * C + ((Y - X) * B if (X < Y) else (X - Y) * A)

print(min([p1, p2, p3]))
