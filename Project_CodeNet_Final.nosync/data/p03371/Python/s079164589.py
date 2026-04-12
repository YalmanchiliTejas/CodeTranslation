A, B, C, X, Y = map(int, input().split())
s1 = A * X + B * Y
s2 = A * (X - min(X, Y)) + B * (Y - min(X, Y)) + C * 2 * min(X, Y)
s3 = C * 2 * max(X, Y)
print(min(s1, s2, s3))