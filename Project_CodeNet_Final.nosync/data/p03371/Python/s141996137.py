A, B, C, X, Y = map(int, input().split())
all = X*A + Y*B
all_ab = 2 * C * max(X, Y)
m = min(X, Y)
almost_ab = 2 * C * m + A * (X - m) + B * (Y - m)
print(min(all, all_ab, almost_ab))