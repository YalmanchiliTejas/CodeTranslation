A, B, C, X, Y = list(map(int, input().split()))

s1 = A * X + B * Y

s2 = C * max(X, Y) * 2

if X > Y:
    s3 = C * (Y * 2) + A * (X - Y)
elif Y > X:
    s3 = C * (X * 2) + B * (Y - X)
else:
    s3 = 10**10

print(min(s1, s2, s3))