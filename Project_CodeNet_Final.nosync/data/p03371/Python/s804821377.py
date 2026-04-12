A, B, C, X, Y = map(int, input().split())

ans = 0
if A + B <= C * 2:
    ans = A * X + B * Y
else:
    if X > Y:
        ans = C * Y * 2 + (X - Y) * min(A, C * 2)
    elif X == Y:
        ans = C * X * 2
    else:
        ans = C * X * 2 + (Y - X) * min(B, C * 2)
print(ans)
