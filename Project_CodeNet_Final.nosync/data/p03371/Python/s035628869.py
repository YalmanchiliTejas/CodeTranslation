A, B, C, X, Y = map(int, input().split())

d = X * A + Y * B
e = 2 * C * max(X, Y)
f = 2 * C * min(X, Y) + (X - min(X, Y)) * A + (Y - min(X, Y)) * B
print(min(d, e, f))