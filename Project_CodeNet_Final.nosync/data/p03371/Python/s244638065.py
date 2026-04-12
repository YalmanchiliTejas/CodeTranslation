A, B, C, X, Y = map(int, input().split())

ans = float("inf")

if X > Y:
    ab = 2 * X
    while ab >= 0:
        a = X - (ab / 2)
        if ab / 2 < Y:
            b = int(Y - ab / 2)
        else:
            b = 0
        money = a * A + b * B + ab * C
        ans = min(ans, money)
        ab -= 2
else:
    ab = 2 * Y
    while ab >= 0:
        b = Y - (ab / 2)
        if ab / 2 < X:
            a = int(X - ab / 2)
        else:
            a = 0
        money = a * A + b * B + ab * C
        ans = min(ans, money)
        ab -= 2
print(int(ans))
