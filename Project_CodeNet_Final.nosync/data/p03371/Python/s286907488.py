A, B, C, X, Y = map(int, input().split())
r = 0

if A+B >= 2*C:
    t = min(X, Y)
    r += 2 * t * C
    X -= t
    Y -= t
if 2*C <= A:
    r += X * 2 * C
    Y = max(Y-X, 0)
    X = 0
if 2*C <= B:
    r += Y * 2 * C
    X = max(X-Y, 0)
    Y = 0
r += A * X
r += B * Y
print(r)
