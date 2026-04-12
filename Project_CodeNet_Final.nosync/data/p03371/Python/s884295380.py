A, B, C, X, Y = map(int, input().split())
a, b, c = 0, 0, 0

tmp = min(X, Y)
if tmp * A + tmp * B < tmp * C * 2:
    a += tmp
    b += tmp
else:
    c += tmp * 2
X -= tmp
Y -= tmp
if X:
    if C * 2 < A:
        c += X * 2
    else:
        a += X
if Y:
    if C * 2 < B:
        c += Y * 2
    else:
        b += Y
print(a * A + b * B + c * C)


