A, B, C, X, Y = map(int, input().split())
naive = A * X + B * Y

if X < Y:
    recon = 2 * C * X + B * (Y - X)
else:
    recon = 2 * C * Y + A * (X - Y)

over = 2 * C * max(X, Y)

print(min(naive, recon, over))