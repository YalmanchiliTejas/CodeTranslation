A, B, C, X, Y = map(int, input().split())

a1 = A * X + B * Y

a2 = min(X, Y) * 2 * C
if X >= Y:
    a2 += (X - Y) * min(A, 2 * C)
else:
    a2 += (Y - X) * min(B, 2 * C)

ans = min(a1, a2)
print(ans)
