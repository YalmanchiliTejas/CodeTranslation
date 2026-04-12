A, B, C, X, Y = map(int, input().split())

if A + B >= C * 2:
    if X > Y:
        ans = min((C * (Y * 2) + A * (X - Y)), C * X * 2)
    else:
        ans = min((C * (X * 2) + B * (Y - X)), C * Y * 2)
else:
    ans = A * X + B * Y

print(ans)