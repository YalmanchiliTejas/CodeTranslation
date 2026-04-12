A, B, C, X, Y = map(int, input().split())
if A + B <= 2 * C:
    print(A * X + B * Y)
else:
    if X > Y:
        A, B, X, Y = B, A, Y, X
    print(2 * X * C + (Y - X) * min(B, 2 * C))
