A, B, C, X, Y = map(int, input().split())
ans = A * X + B * Y
for i in range(max(X, Y)):
    ans_temp = ans
    if i >= X:
        ans_temp += A
    if i >= Y:
        ans_temp += B
    ans = min(ans, ans_temp - A - B + 2 * C)
print(ans)
