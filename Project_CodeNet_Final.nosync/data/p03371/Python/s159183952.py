import sys

A, B, C, X, Y = map(int, sys.stdin.readline().split(" "))

ans = 0
if A + B >= 2 * C:
    c_count = 2 * min(X, Y)
    ans = c_count * C
    X -= c_count // 2
    Y -= c_count // 2

ans += min(A * X, C * 2 * X)
ans += min(B * Y, C * 2 * Y)

print(ans)