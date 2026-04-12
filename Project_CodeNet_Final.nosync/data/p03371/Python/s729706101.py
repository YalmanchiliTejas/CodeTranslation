A, B, C, X, Y = map(int, input().split())

ab = A * X + B * Y
Ab = C * X * 2 + B * (Y-X if Y > X else 0)
aB = C * Y * 2 + A * (X -Y if X > Y else 0)
print(min(ab, Ab, aB))