A, B, C, X, Y = map(int,input().split())
if A + B <= 2 * C:
    ans = A * X + B * Y
elif 2 * C <= A and 2 * C <= B:
    ans = 2 * C * max(X, Y)
elif 2 * C <= A:
    ans = 2 * C * X + B * max(0, Y - X)
elif 2 * C <= B:
    ans = 2 * C * Y + A * max(0, X - Y)
else:
    if X < Y:
        ans = 2 * C * X + B * (Y - X)
    else:
        ans = 2 * C * Y + A * (X - Y)
print(ans)