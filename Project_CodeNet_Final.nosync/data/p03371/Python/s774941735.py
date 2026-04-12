A, B, C, X, Y = list(map(int, input().split()))
pri = 0

if A + B <= 2 * C:
    pri = A * X + B * Y
else:
    while min(X, Y) != 0:
        pri += C * 2
        X -= 1
        Y -= 1
    if A * X + B * Y >= 2 * C * (X + Y):
        pri += 2 * C * (X + Y)
    else:
        pri += A * X + B * Y

print(pri)
