# C - Half and Half

A, B, C, X, Y = map(int, input().split())

ans = A*X + B*Y
if A+B > C*2:
    m = min(X, Y)
    ans -= (A+B-(C*2)) * m
    X -= m
    Y -= m
if X > 0 and A > C*2:
    ans -= (A-(C*2)) * X
    Y -= X
if Y > 0 and B > C*2:
    ans -= (B-(C*2)) * Y
    Y -= Y

print(ans)