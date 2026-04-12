A, B, C, X, Y = map(int, input().split())

if Y - X > 0:
    ans_1 = min(X, Y) * C * 2 + (Y - X) * B
else:
    ans_1 = min(X, Y) * C * 2 + (X - Y) * A

ans_2 = max(Y, X) * C * 2

ans_3 = X * A + Y * B

print(min(ans_1, ans_2, ans_3))