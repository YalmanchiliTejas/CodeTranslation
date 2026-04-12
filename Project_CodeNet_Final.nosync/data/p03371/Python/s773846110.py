A, B, C, X, Y = map(int, input().split())
s1 = A * X + B * Y
if X <= Y:
    c = C * 2 * X
    b = B * (Y - X)
    s2 = b + c
    s3 = C * 2 * Y
    print(min(s1, s2, s3))
else:
    c = C * 2 * Y
    a = A * (X - Y)
    s2 = a + c
    s3 = C * 2 * X
    print(min(s1, s2, s3))
