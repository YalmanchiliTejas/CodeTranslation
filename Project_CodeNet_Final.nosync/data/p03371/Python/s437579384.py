A, B, C, X, Y = map(int, input().split())

v1 = (C * 2) * max(X, Y)
v2 = (C * 2) * min(X, Y)
if X > Y:
    v2 += (X - Y) * A
else:
    v2 += (Y - X) * B
v3 = (A * X) + (B * Y)

print(min(v1, v2, v3))