A, B, C, X, Y = map(int, input().split())
ans = A * X + B * Y
M = max(X, Y)
N = min(X, Y)
if A + B > C * 2:
    ans -= N * (A + B) - 2 * C * N
    if A > 2 * C and X > Y:
        ans = 2 * C * X
    elif B > 2 * C and X < Y:
        ans = 2 * C * Y
print(ans)
