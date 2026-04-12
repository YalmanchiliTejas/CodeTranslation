A, B, C, X, Y = map(int, input().split())
all = A * X + B * Y
all_half = max(X, Y) * C * 2
best = (min(X, Y) * C * 2) + A * (X - min(X, Y)) + B * (Y - min(X, Y))
print(min(all, all_half, best))