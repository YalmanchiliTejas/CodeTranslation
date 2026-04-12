A, B, C, X, Y = map(int, input().split())


ans = 0
if C * 2 <= A + B:
    ans = C * min(X, Y) * 2
else:
    ans = A * min(X, Y) + B * min(X, Y)

if Y < X and C * 2 < A:
    ans = ans + (X - Y) * C * 2
elif Y < X:
    ans = ans + (X - Y) * A
elif X < Y and C * 2 < B:
    ans = ans + (Y - X) * C * 2
elif X < Y:
    ans = ans + (Y - X) * B
else:
    pass
print(ans)