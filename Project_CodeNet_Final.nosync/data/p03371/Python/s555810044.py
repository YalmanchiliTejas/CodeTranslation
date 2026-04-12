A, B, C, X, Y = [int(_) for _ in input().split()]
C*=2

if X > Y:
    X, Y = Y, X
    A, B = B, A
ans = 0
if X * (A + B) > X * C:
    ans += X * C
    Y -= X
else:
    ans += X * A

ans += min(B * Y, Y * C)
print(ans)
