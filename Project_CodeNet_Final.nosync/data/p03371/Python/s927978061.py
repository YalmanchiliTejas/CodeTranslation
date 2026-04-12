A, B, C, X, Y = map(int, input().split())
ans = 0
#A+B < 2ABの場合はそれぞれ単品で買ったほうがお得
if A + B < 2 * C:
    ans = A*X + B*Y
#A+B > 2ABの場合は買えるだけかう
else:
    for _ in range(min(X, Y)):
        ans += 2 * C

    if X - Y >= 0:
        if A < 2 * C:
            ans += A * (X-Y)
        else:
            ans += 2 * C * (X-Y)
    else:
        if B < 2 * C:
            ans += B * (Y-X)
        else:
            ans += 2 * C * (Y-X)

print(ans)