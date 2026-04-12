A, B, C, X, Y = map(int, input().split())
ans = 0
a = b = c = 0

if A + B > 2*C:
    mi = min(X, Y)
    ans += (mi * 2) * C
    X -= mi
    Y -= mi
    c += mi*2

if B > 2*C:
    ans += (Y * 2) * C
    Y = 0
    if X > Y:
        X -= Y
    else:
        X = 0
    c += Y*2
if A > 2*C:
    ans += (X * 2) * C
    X = 0
    if Y > X:
        Y -= X
    else:
        Y = 0
    c += X*2

ans += A*X + B*Y
a = X
b = Y

print(ans)
