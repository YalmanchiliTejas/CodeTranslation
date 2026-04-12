A, B, C, X, Y = map(int, input().split())
all = A * X + B * Y
all_half = max(X, Y) * C * 2
m = min(X, Y)
appropriate_half = (m * C * 2) + A * (X - m) + B * (Y - m)
print(min(all, all_half, appropriate_half))