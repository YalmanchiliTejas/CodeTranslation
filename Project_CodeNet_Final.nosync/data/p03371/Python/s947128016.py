A, B, C, X, Y = map(int, input().split())
C *= 2

ans = 0

if C <= A:
    ans += X * C
    Y -= X
    X = 0

if Y > 0 and C <= B:
    ans += Y * C
    X -= Y
    Y = 0

if X > 0 and Y > 0 and C <= A + B:
    cnt = min(X, Y)
    ans += cnt * C
    X -= cnt
    Y -= cnt

if X > 0:
    ans += X * A
    X = 0

if Y > 0:
    ans += Y * B
    Y = 0

print(ans)
