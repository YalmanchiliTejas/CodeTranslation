from math import ceil
A, B, C, X, Y = map(int, input().split())
ans = float('inf')

ans = min(ans, A * X + B * Y)
ans = min(ans, C * max(X, Y) * 2)

if X > Y:
    num = 2 * Y
    ans = min(ans, num * C + ceil(X - Y) * A)
else:
    num = 2 * X
    ans = min(ans, num * C + ceil(Y - X) * B)
print(ans)
