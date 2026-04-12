A,B,C,X,Y = map(int, open(0).read().split())

if (C * 2) < (A + B):
    n = min(X, Y)
    ans = (C * n * 2)
    x = X - n
    y = Y - n
    if x > 0:
        if A < C * 2:
            ans += x * A
        else:
            ans += x * C * 2
            y -= x
    if y > 0:
        if B < C * 2:
            ans += y * B
        else:
            ans += y * C * 2
else:
    ans = A * X + B * Y

print(ans)