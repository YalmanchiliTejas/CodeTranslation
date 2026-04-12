A, B, C, X, Y = map(int, input().split())

res = 0

if A + B > C * 2:
    if X > Y:
        res = min(Y * C * 2 + (X - Y) * A, X * C * 2)
    else:
        res = min(X * C * 2 + (Y - X) * B, Y * C * 2)

else:
    res = A * X + B * Y

print(res)