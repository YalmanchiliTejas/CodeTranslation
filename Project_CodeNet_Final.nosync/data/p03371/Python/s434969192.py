A, B, C, X, Y = map(int, input().split())
ans = 0
if 2 * C < A + B:
    ans += min(X, Y) * 2 * C
    if X >= Y:
        ans += (X - Y) * min(A, 2 * C)
    else:
        ans += (Y - X) * min(B, 2 * C)
else:
    ans = X * A + Y * B
print(ans)
